# PLANAR_GRAPH_FACE_FINDER (PGFF)
PGFF é um programa que recebe um grafo $G(V,E)$ e encontra todas as suas faces. Esse programa é o produto de uma atividade prática da disciplina de Algoritmos I do [Departamento de Ciência da Computação da UFMG](https://dcc.ufmg.br/).

## Sumário
- [Compilação](#Compilação)
- [Execução](#Execução)
- [Documentação](#Documentação)

# Compilação
PGFF pode ser compilado com o seguinte comando:

``` sh
$ ./run --build
```

OBS.: O programa foi desenvolvido e testado utilizando o g++12. Certifique-se de utilizar esta versão do compilador.

# Execução
A execução pode ser realizada tanto pelo script python: ``./run --exec``

quanto pela execução direta do executável: ``bin/Release/program``

## Formato de Entrada
A primeira linha contém dois inteiros, $N$ e $M$, que representam o número de vértices e arestas do grafo de entrada $G$.

A $i$-ésima linha da entrada começa com dois números reais $x_{i}, y_{i}$, que representam as coordenadas do vértice $i$ no plano cartesiano.
Ainda na mesma linha, temos um inteiro positivo $d_{i}$, que representa o grau do vértice $i$.
Em seguida, $d_{i}$ inteiros entre $1$ e $N$ são fornecidos, cada um correspondendo a um vizinho de $i$.

Obs.: O programa foi testado para $1 \le N, M \le 10^{5}$ e para $-10^{4} \le x_{i}, y_{i} \le 10^{4}$

## Formato de Saída
A saída do programa é formatada da seguinte maneira:
- A primeira linha da saída contém um inteiro $F$, que representa o número de faces no grafo $G$.
- As próximas $F$ linhas correspondem às faces do grafo $G$. Cada linha começa com um inteiro $s_{i}$, que representa o tamanho da $i$-ésima face de $G$. Em seguida, existem $s_{i}$ inteiros, representando o circuito que corresponde à borda da face.

# Documentação
O enunciado deste trabalho pode ser lido [aqui](https://github.com/luk3rr/PLANAR_GRAPH_FACE_FINDER/tree/main/docs).
