/*
* Filename: graph.h
* Created on: September 13, 2023
* Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
*/

#ifndef GRAPH_H_
#define GRAPH_H_

#include <math.h>
#include <cstdint>
#include <iostream>
#include <utility>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>

#include "vertex.h"
#include "geometry_utils.h"

namespace geom {
    class Graph {
        private:
            // A posição no vetor é o ID do vértice
            std::vector<Vertex> m_vertices;

            uint32_t m_numEdges;

            /**
             * @brief Ordenada a lista de vizinhos de todos os vértices de acordo com o ângulo polar
             **/
            void SortNeighborsList();

            /**
             * @brief A partir de um vértice, encontra o próximo vértice que deve ser visitado para formar uma face
             * @param previousVertex ID do vértice que visitamos antes de visitar o vértice atual
             * @param currentVertex ID do vértice atual
             * @return Edge Aresta que devemos percorre para chegar ao próximo vértice
             **/
            Edge* GetNextVertexFromCurrentVertexNeighborsList(uint32_t previousVertex, uint32_t currentVertex);

            /**
             * @brief Dado o arco (a,b), encontra a face na qual ela faz parte
             **/
            void FindFace(uint32_t a, uint32_t b);

        public:
            ~Graph();

            /**
             * @param numVertices Quantidade de vértices do grafo
             * @param numEdges Quantidade de bordas do grafo
             **/
            Graph(uint32_t numVertices, uint32_t numEdges);

            /**
             * @brief Adiciona um vértice ao grafo
             * @param vertex Novo vértice do grafo
             **/
            void AddVertex(Vertex vertex);

            /**
             * @brief Adiciona um determinado vértice como vizinho de outro
             * @param vertexID ID do vértice que receberá um vizinho
             * @param neighborID ID do vizinho
             **/
            void AddNeighbor(uint32_t vertexID, uint32_t neighborID);

            /**
             * @brief Encontra todas as faces do vértice planar
             **/
            void FindFaces();
    };
}

#endif // GRAPH_H_
