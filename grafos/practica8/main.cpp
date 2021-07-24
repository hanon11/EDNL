#include <iostream>
#include "../alg_grafo_E-S.hpp"
#include "../grafoMA.hpp"
#include "1.hpp"
#include "2.hpp"
#include "5.hpp"
#include "6.hpp"

int main()
{
    Grafo G1("1.dat");
    vector<isla<double> > islas;
    islas.insert(islas.end(), isla<double>(0,0));
    islas.insert(islas.end(), isla<double>(1,1));
    islas.insert(islas.end(), isla<double>(2,2));
    islas.insert(islas.end(), isla<double>(3,3));
    islas.insert(islas.end(), isla<double>(4,4));
    //tombuctu2(G1, islas);
    GrafoP<unsigned> G5("5.dat");
    //reteuni3(G5);
    GrafoP<double> costes("5.dat"), G6("5.dat");
    canales(G6, costes, 2.1, 5.4);
}