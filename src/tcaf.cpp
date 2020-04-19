#include "../include/tcaf.h"


TCAF::TCAF(void)
{

}

float TCAF::axial_force(float x, float v)
{
    return (stiffness_force(x, v) + friction_force(x, v) + cutting_force(x, v));
}


float TCAF::stiffness_force(float x, float v)
{   
    float fs = 0; x = x * 1000.0f;
    if (x < m_x1) { fs = 0; }
    else if (x >= m_x1 && x <= m_x2) { fs = m_a1 * x + m_a2 * powf(x, 2); }
    else { fs = 0; }

    return fs;
}

float TCAF::friction_force(float x, float v)
{
    return 0;
}

float TCAF::cutting_force(float x, float v)
{
    float fc = 0; x = x * 1000.0f;
    if (x <= m_x2) { fc = 0; }
    else if (x > m_x3) { fc = m_fc; }
    else { fc = 0; }
    return fc;
}
