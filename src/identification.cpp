#include "../include/identification.h"


Identification::Identification()
{

}

void Identification::resampling(arma::fmat *matr, float ts)
{
    arma::fvec t = (*matr).col(0);

    // float t_total = t(t.n_rows - 1) - t(0);

    arma::fvec tu = arma::regspace<arma::fvec>(t.front(), ts, t.back());

    arma::mat mat_u(tu.n_rows, (*matr).n_cols); mat_u.zeros();
    

    // for (int64_t i = 0; i < samples; i++)
    // {   
    //     float tc = t(0) + i*ts;
    // }

}