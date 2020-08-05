CC = g++

breadth: 
	$(CC) -std=c++11 -O3 ./src/breadth.cpp ./src/data.cpp ./src/hungarian.cpp -o tsp_bb_deapth

deapth: 
	$(CC) -std=c++11 -O3 ./src/deapth.cpp ./src/data.cpp ./src/hungarian.cpp -o tsp_bb_breadth

cleanBreadth:
	rm tsp_bb_breadth

cleanDeapth:
	rm tsp_bb_deapth