#ifndef IDENTIFICATION_H
#define IDENTIFICATION_H

#include <iostream>
#include <armadillo>


class Identification
{
    public:
        Identification();
        
        void resampling(arma::fmat *matr, float ts);
        
    private:

};


#endif 