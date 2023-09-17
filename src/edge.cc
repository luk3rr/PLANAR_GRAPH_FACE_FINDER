/*
* Filename: edge.cc
* Created on: September 17, 2023
* Author: Lucas Araújo <araujolucas@dcc.ufmg.br>
*/

#include "edge.h"

namespace geom {
    Edge::Edge(uint32_t dest) {
        m_dest = dest;
        m_traversed = false;
    }

    bool Edge::operator<(const Edge &other) {
        return this->m_polarAngle < other.m_polarAngle;
    }

    void Edge::SetPolarAngle(double_t polarAngle) {
        this->m_polarAngle = polarAngle;
    }

    void Edge::SetTraversed(bool value) {
        this->m_traversed = value;
    }

    uint32_t Edge::GetDest() {
        return this->m_dest;
    }

    double_t Edge::GetPolarAngle() {
        return m_polarAngle;
    }

    bool Edge::WasTraversed() {
        return m_traversed;
    }
}
