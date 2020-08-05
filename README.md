# Traveling Salesman Problem (TSP)

O TSP se trata de um problema de otimização combinatória da classe NP-difícil bastante conhecido e estudado na literatura.

Para entender o problema, imagine um vendedor com um conjunto pré-determinado de clientes onde cada cliente possui um custo de viagem (que pode ser tempo, distância ou qualquer variável relevante) dele para os outros clientes, ou seja, o custo de viagem do cliente N1 para o cliente N2 pode ser 200 enquanto do N1 para o N3 150. A ideia é que o vendedor passe por cada cliente somente uma vez e tenha que voltar ao ponto de partida no fim do percurso. Para reduzir custos, é necessário escolher uma rota, dentre todas as rotas possíveis, onde o somatório dos custos da viagem entre os clientes seja a menor.

## Formas de resolução

Existem dois métodos que podem ser seguidos para resolver problemas como o descrito anteriormente, os exatos ou os heurísticos.

Métodos exatos visam iterar sobre todo o conjunto de soluções de um problema para obter sua resposta. Por conta disso, eles retornam a solução ótima do problema, ou seja, a melhor dentre todas as soluções. Por outro lado, para problemas da classe NP, não é possível encontrar estas soluções em tempo computacional aceitável a partir de certo ponto. Para ilustrar, uma instância do TSP com 60 vértices possui uma quantidade de soluções possíveis semelhante a quantidade de átomos no universo!

Por outro lado, existem os métodos heurísticos, que tentar resolver estes problemas com um tempo computacional aceitável sem garantir sua otimalidade, mas que podem trazer boas soluções, e os meta-heurísticos, que tem a mesma finalidade, porém com o intuito de resolver vários tipos de problemas diferentes com um mesmo algoritmo.

O algorítmio implementado neste repositório para resolver o TSP se trata de um algorítimo inteiro denominado [Branch and Bround](https://pt.wikipedia.org/wiki/Branch_and_bound), com dois tipos de pesquisa, em árvore, profundidade e largura, em conjunto com o algorítimo [Hungaro](https://en.wikipedia.org/wiki/Hungarian_algorithm).

## Instância do TSP

As instâncias do TSP são criado a partir de um conjunto de cidades, cada uma com sua localização geográfica. Em posse desses dados, os custos de deslocamento podem ser calculados para cada par de cidades, onde é descrito por uma matriz, podendo esta ser simétrica ou assimétrica.

As instâncias contidas neste repositório são **simétricas**, e estão todas localizadas em `./instances` ou podem ser obtidas no [TSPLIB](http://elib.zib.de/pub/mp-testdata/tsp/tsplib/tsplib.html), onde também contêm os resultados ótimos de cada instância obtidos por métodos exatos. Segue um exemplo de matriz simétrica para um problema com 4 vértices.

```
M = | -- 10 20 30 |
    | 10 -- 10 20 |
    | 20 10 -- 10 |
    | 30 20 10 -- |
```

## Compilar

``` bash
make breadth
ou
make deapth
```

## Executar
Substitua INSTÂNCIA por qualquer instância dentro da pasta `./instances` e UPPERBOUND por um valor interio caso seja conhecido, caso não, pode ser descartado.

``` bash
./tsp_bb_breadth instances/INSTANCIA UPPERBOUND
 ou
./tsp_bb_deapth instances/INSTANCIA UPPERBOUND
```

## Resultados

A presente implementação do algoritmo consegue encontrar os resultados ótimos para todas as instâncias, porém, por conta de sua natureza combinatória, rapidamente alcança um tempo computacional não aceitável.

## TODO

* Criar tabela com os resultados computacionais
