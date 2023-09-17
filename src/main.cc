/*
* Filename: main.cc
* Created on: September 13, 2023
* Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
*/

#include <cmath>
#include <cstdint>
#include <iostream>
#include <cstdlib>

#include "graph.h"

int main(int argc, char *argv[]) {
    uint32_t numVertices, numEdges, degree, neighbor;
    double_t coordX, coordY;

    std::cin >> numVertices >> numEdges;

    geom::Graph graph(numVertices, numEdges);

    for (uint32_t i = 0; i < numVertices; i++) {
        std::cin >> coordX >> coordY >> degree;

        // Vertex é criado com: Coordenada (X,Y) e ID
        graph.AddVertex(geom::Vertex(coordX, coordY, i));

        for (uint32_t j = 0; j < degree; j++) {
            std::cin >> neighbor;

            // Os IDs dos vizinhos vão de {1, 2,..., N}, mas o código lida com {0,1,...,N - 1}
            graph.AddNeighbor(i, neighbor - 1);
        }
    }

    graph.FindFaces();

    return EXIT_SUCCESS;
}
