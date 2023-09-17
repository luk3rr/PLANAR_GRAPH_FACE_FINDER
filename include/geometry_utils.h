/*
* Filename: geometry_utils.h
* Created on: June  7, 2023
* Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
*/

#ifndef GEOMETRY_UTILS_H_
#define GEOMETRY_UTILS_H_

#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cstdint>

#include "vertex.h"

#define PI 3.14159265359

namespace geom {
    class Utils {
        public:
            /**
             * @brief Calcula o ângulo polar do ponto 'a' com relação ao ponto 'ref'
             * @param ref Ponto de referência para o cálculo do ângulo polar
             * @param a Ponto que será utilizando no cálculo do ângulo
             * @return Valor do ângulo em radianos
             */
            static double_t PolarAngle(Vertex ref, Vertex a);
    };
}

#endif // GEOMETRY_UTILS_H_
