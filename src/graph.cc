/*
* Filename: graph.cc
* Created on: September 13, 2023
* Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
*/

#include "graph.h"

namespace geom {
    Graph::~Graph() { }

    Graph::Graph(uint32_t numVertices, uint32_t numEdges) {
        // Redimensiona a lista e a matriz de adjacência de acordo com o número de vértices do grafo
        this->m_vertices.resize(numVertices);
        this->m_numEdges = numEdges;
    }

    void Graph::AddVertex(Vertex newVertex) {
        this->m_vertices[newVertex.GetID()] = newVertex;
    }

    void Graph::AddNeighbor(uint32_t vertexID, uint32_t neighborID) {
        std::vector<Edge>* neighborsList = this->m_vertices[vertexID].GetNeighborsList();
        neighborsList->push_back(geom::Edge(neighborID));
    }

    void Graph::FindFaces() {
        SortNeighborsList();

        /* Ideia do algoritmo
         * - Pegue um vértice aleatório e o chame de startVertex, currentVertex e previousVertex
         *   - Registre startVertex na sequência
         *
         * - Na lista ordenada de vizinhos do currentVertex, pegue o primeiro vértice e o chame de nextVertex
         *   - Atualize previousVertex para ser currentVertex
         *   - Atualize currentVertex para ser nextVertex
         *   - Registre currentVertex na sequência
         *   - Remova currentVertex da lista de vizinhos de previousVertex
         *
         * - Na lista ordenada de vizinhos do currentVertex, pegue o vértice imediatamente após previousVertex e o chame de nextVertex
         *   - Atualize previousVertex para ser currentVertex
         *   - Atualize currentVertex para ser nextVertex
         *   - Registre currentVertex na sequência
         *   - Remova currentVertex da lista de vizinhos de previousVertex
         *
         * Repita o processo até voltar em startVertex
         **/

        uint32_t numVertices = this->m_vertices.size();
        // Fórmula de Euler para o número de faces de um grafo planar
        std::cout << 2 + this->m_numEdges - numVertices << std::endl;

        for (uint32_t i = 0; i < numVertices; i++) {
            std::vector<Edge>* neighborsList = m_vertices[i].GetNeighborsList();

            // Itere sobre cada vértice vizinho de i em busca de um arco que ainda não foi percorrido
            for (auto edge : *neighborsList) {
                if (not edge.WasTraversed()) {
                    edge.SetTraversed(true);
                    FindFace(i, edge.GetDest());
                }
            }
        }
    }

    void Graph::SortNeighborsList() {
        // Variáveis auxiliares para melhorar a legibilidade do código
        uint32_t neighborID;
        double_t polarAngle;

        for (uint32_t i = 0; i < this->m_vertices.size(); i++) {
            std::vector<Edge>* neighborsList = this->m_vertices[i].GetNeighborsList();

            // Itera sobre cada vizinho do vértice i e ordenada seus vizinhos de acordo com o ângulo polar
            for (uint32_t j = 0; j < neighborsList->size(); j++) {
                neighborID = neighborsList->at(j).GetDest();

                polarAngle = Utils::PolarAngle(m_vertices[i], m_vertices[neighborID]);
                neighborsList->at(j).SetPolarAngle(polarAngle);
            }

            std::sort(neighborsList->begin(), neighborsList->end());
        }
    }

    Edge* Graph::GetNextVertexFromCurrentVertexNeighborsList(uint32_t previousVertex, uint32_t currentVertex) {
        std::vector<Edge>::iterator neighbor;
        std::vector<Edge>* neighborsList = m_vertices[currentVertex].GetNeighborsList();

        for (neighbor = neighborsList->begin(); neighbor != neighborsList->end(); ++neighbor) {
            if (neighbor->GetDest() == previousVertex) {
                // Se for o último elemento do vetor, então o próximo será o primeiro elemento do vetor
                neighbor++;
                if (neighbor == neighborsList->end())
                    return &(*neighborsList->begin()); // Retorna o endereço da Edge armazenada na primeira posição do vector de vizinhos

                else
                    return &(*neighbor); // Retorna o endereço da Edge
            }
        }

        return nullptr; // Esse caso nunca deve ocorrer, compilador chato reclamando de que a função não é void
    }

    void Graph::FindFace(uint32_t a, uint32_t b) {
        std::string face;
        face.clear();

        uint32_t previousVertex = a;
        uint32_t currentVertex = b;
        uint32_t edgesCounter = 1;

        Edge* edge = GetNextVertexFromCurrentVertexNeighborsList(previousVertex, currentVertex);
        uint32_t nextHop = edge->GetDest();

        while (previousVertex != a or nextHop != b) { // Percorra o grafo até voltar na primeira borda percorrida
            edge->SetTraversed(true);
            face += std::to_string(previousVertex + 1) + " ";

            edge = GetNextVertexFromCurrentVertexNeighborsList(previousVertex, currentVertex);
            nextHop = edge->GetDest();

            previousVertex = currentVertex;
            currentVertex = nextHop;
            edgesCounter++;
        }

        std::cout << edgesCounter  << " " << face << previousVertex + 1 << std::endl;
        face.clear();
    }
}
