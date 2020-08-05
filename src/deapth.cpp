#include <iostream>
#include <vector>
#include<bits/stdc++.h> 
using namespace std;

#include "data.h"
#include "hungarian.h"

int uperBound = INT_MAX;
vector< vector<int> > finalRoute;

void solve(double** costMatrix, int dimension, int v1Constraint, int v2Constraint) {
	int initialVertice = 0, currentVertice;
	int smallerTour = 0, remainingVertices = dimension-1;
	double obj_value, saveCost = 0;
	vector<int> route, vertices(dimension, 0);
	vector< vector<int> > routes;
	hungarian_problem_t problem;

	//Add constraint
	if (v1Constraint != -1) {
		saveCost = costMatrix[v1Constraint][v2Constraint];
		costMatrix[v1Constraint][v2Constraint] = 99999980;
	}

	//Resolve problem
	hungarian_init(&problem, costMatrix, dimension, dimension, HUNGARIAN_MODE_MINIMIZE_COST);
	obj_value = hungarian_solve(&problem);

	//Get routes
	for (int tours = 0; remainingVertices > 0; tours++) {
		//Search for init a new cicle
		for (int i = 0; i < dimension; i++) {
			if (vertices[i] == 0) {
				initialVertice = i;
				break;
			}
		}

		//Create a new route
		currentVertice = initialVertice;
		routes.push_back(route);
		routes[tours].push_back(currentVertice);
		vertices[currentVertice] = 1;

		//Insert vertices a route
		while (1) {
			for (int j = 0; j < dimension; j++) {
				if (problem.assignment[currentVertice][j] == 1) {
					currentVertice = j;
					vertices[j] = 1;
					routes[tours].push_back(j);
					remainingVertices--;
					break;
				}
			}

			if (currentVertice == initialVertice) break;
		}

		//Verify if current rout is a smaller
		if (routes[tours].size() < routes[smallerTour].size()) smallerTour = tours;
	}

	//Cases
	if (obj_value > uperBound) { //Cut
	}
	else if (routes.size() == 1) { //Leaf of a tree
		if (obj_value < uperBound) {
			//Update values of a best route
			uperBound = obj_value;
			finalRoute = routes;
		}
	}
	else { //Branch
	 //Create a branch for each vertice
		for (int i = 0; i < routes[smallerTour].size()-1; i++) {
			solve(costMatrix, dimension, routes[smallerTour][i], routes[smallerTour][i+1]);
		}
	}

	//Update and returns
	if (v1Constraint != -1) costMatrix[v1Constraint][v2Constraint] = saveCost;
	hungarian_free(&problem);
	return;
};

int main(int argc, char** argv) {
	//Get data
	Data * data = new Data(argc, argv[1]);
	data->readData();

	if (argc == 3) {
		uperBound = atoi(argv[2]);
	}

	//Get cost matrix
	double **cost = new double*[data->getDimension()];
	for (int i = 0; i < data->getDimension(); i++) {
		cost[i] = new double[data->getDimension()];
		for (int j = 0; j < data->getDimension(); j++) {
			cost[i][j] = data->getDistance(i, j);
		}
	}

	//Resolve
	solve(cost, data->getDimension(), -1, -1);

	//Show result
	cout << "UperBound: " << uperBound << endl;
	cout << "Tour: " << endl;
	for (int i = 0; i < finalRoute.size(); i++) {
		for (int j = 0; j < finalRoute[i].size(); j++) {
			cout << finalRoute[i][j] << " ";
		}
		cout << endl;
	}

	//Free up space
	for (int i = 0; i < data->getDimension(); i++) delete[] cost[i];
	delete[] cost;
	delete data;

	return 0;
}
