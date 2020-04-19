#include <iostream>
#include <armadillo>

#include "./include/matplot/matplot.hpp"
#include "./include/armaext.hpp"

#include "./include/identification.h"
#include "./include/tcaf.h"


int main(int argc, char *argv[])
{
    
    // Sample size 
    const int n = 1000;

    // Insertion depth 
    const float ins_depth = 35.0f / 1000.0f; // (m)

    // Depth vector (m)
    arma::fvec depth = arma::linspace<arma::fvec>(0.0f, ins_depth, n);

    // Insertion velocity vector (m/s) 
    arma::fvec insertion_vel(n); insertion_vel.fill(0.003);

    // Force model
    TCAF force_model;

    arma::fvec axial_force(n, arma::fill::zeros);

   for (int i = 0; i < n; i++)
    {
        axial_force(i) = force_model.axial_force(depth(i), insertion_vel(i));
    }

    // Read Okamura's model
    std::string model_filename = "./share/okamura_model.csv";
    arma::fmat data; data.load(model_filename, arma::csv_ascii);
    ArmaExt::sortrows<arma::fmat>(&data, true);
    arma::fvec depth_okamura = data.col(0) / 1000.0f;
    arma::fvec force_okamura = data.col(1);


    // Resample model
    Identification arx;
    arx.resampling(&data, 0.1);

   // Plots
    MatPlot<arma::fvec> fig1;
    fig1.plot2D(depth, axial_force, "b");
    fig1.plot2D(depth_okamura, force_okamura, "r.");
    fig1.grid();
    fig1.show();

    return 0;
}


