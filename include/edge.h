/*
* Filename: edge.h
* Created on: September 17, 2023
* Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
*/

#ifndef EDGE_H_
#define EDGE_H_

#include <cmath>
#include <cstdint>

namespace geom {
    class Edge {
        private:
            uint32_t m_dest; // Vértice de destino
            bool m_traversed; // Diz se a aresta foi percorrida ou não
            double_t m_polarAngle; // Ângulo polar da borda

        public:
            Edge(uint32_t dest);

            /**
             * @brief Um arco (a,b) é considerada menor que (a,c) quando o ângulo polar de (a,b) é menor que o ângulo polar de (a,c)
             * @brief
             **/
            bool operator<(const Edge &other);

            /**
             * @brief Define um novo valor para o ângulo polar
             * @param polarAngle Novo valor
             **/
            void SetPolarAngle(double_t polarAngle);

            /**
             * @brief Define se a aresta atual já foi percorrida
             * @param bool Booleano que indica se a aresta atual já foi percorrida
             **/
            void SetTraversed(bool value);

            /**
             * @return ID do vértice de destino dessa aresta
             **/
            uint32_t GetDest();

            /**
             * @return Ângulo polar dessa aresta
             **/
            double_t GetPolarAngle();

            /**
             * @return True se a aresta já foi percorrida, False caso contrário
             **/
            bool WasTraversed();

    };
}

#endif // EDGE_H_
