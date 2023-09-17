/*
* Filename: vertex.h
* Created on: June  5, 2023
* Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
*/

#ifndef VERTEX_H_
#define VERTEX_H_

#include <cmath>
#include <cstdint>
#include <ostream>
#include <utility>
#include <vector>

#include "edge.h"

namespace geom {
    class Vertex {
        private:
            double_t m_x, m_y;
            uint32_t m_id;
            std::vector<Edge> m_neighbors;

        public:
            Vertex();

            /**
             * @brief Overload do construtor da classe
             * @param x, y Coordenadas do ponto
             * @param degree Grau do vértice
             * @param id ID do vértice
             */
            Vertex(double_t x, double_t y, uint32_t id);
            /**
             * @brief Overload do operador ==. Para os critérios desse programa, é suficiente considerar um vértice igual
             *        quando suas coordenadas são iguais. Em outros casos, o ID e os vizinhos podem ser verificados para
             *        definir essa igualdade
             * @param vertex Vértice que será usado na comparação
             * @return True se as coordenadas dos dois vértices forem iguais uma a uma, False caso contrário
             */
            bool operator==(const Vertex &point) const;

            /**
             * @brief Define um novo valor para a coordenada X
             * @param x Novo valor da coordenada X
             */
            void SetX(double_t x);

            /**
             * @brief Define um novo valor para a coordenada Y
             * @param y Novo valor da coordenada Y
             */
            void SetY(double_t y);

            /**
             * @brief Define um novo valor para o ID do vértice
             * @param id Novo valor para o id do vértice
             */
            void SetID(uint32_t id);

            /**
             * @return Valor da coordenada X
             */
            double_t GetX();

            /**
             * @return Valor da coordenada Y
             */
            double_t GetY();

            /**
             * @return Valor do grau do vértice
             */
            uint32_t GetDegree();

            /**
             * @return Valor do ID do vértice
             */
            uint32_t GetID();

            /**
             * @return Endereço do vector de vizinhos do vértice atual
             **/
            std::vector<Edge>* GetNeighborsList();
    };
}

#endif // VERTEX_H_
