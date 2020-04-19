#ifndef TCAF_H  //Three Componet Axial Force
#define TCAF_H


#include <iostream>
#include <cmath>

class TCAF
{
    public:
        TCAF(void);

        float axial_force(float x , float v);

        float stiffness_force(float x, float v);
        float friction_force(float x, float v);
        float cutting_force(float x, float v);

    private:
        float m_a1 = 0.0480; // (N/mm)
        float m_a2 = 0.0061; // (N/mm^2)

        // Global constants
        const float m_x1 = 0.0; // (mm)
        const float m_x2 = 16.7; // (mm)
        const float m_x3 = 16.7; // (mm)

        // Friction force constants
        const float m_dp = 18.45; // (N/m)
        const float m_dn = -18.23; // (N/m)
        const float m_bp = 212.31; // (Ns/m^2)
        const float m_bn = -239.08; // (Ns/m^2)
        const float m_cp = 10.57; // (N/m)
        const float m_cn = -11.96; // (N/m)
        
        // Cutting force constants
        const float m_fc = 0.94; // (N)

};


#endif