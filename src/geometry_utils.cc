/*
* Filename: geometry_utils.cc
* Created on: June  7, 2023
* Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
*/

#include "geometry_utils.h"

namespace geom {
    double_t Utils::PolarAngle(Vertex ref, Vertex a) {
        if (ref == a)
            return 0;

        double_t angle = atan2(a.GetY() - ref.GetY(), a.GetX() - ref.GetX());

        // Ajusta o ângulo em radianos para que fique entre 0 e 2pi
        if (angle < 0) {
            angle += 2 * PI;
        }

        return angle;
    }
}
