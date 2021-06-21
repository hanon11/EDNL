#include <iostream>
#include "../alg_grafo_E-S.hpp"
#include "../grafoMA.hpp"
#include "1.hpp"

int main()
{
    Grafo G1("1.dat");
    vector<isla<double> > islas;
    islas.insert(islas.end(), isla<double>(0,0));
    islas.insert(islas.end(), isla<double>(1,1));
    islas.insert(islas.end(), isla<double>(2,2));
    islas.insert(islas.end(), isla<double>(3,3));
    islas.insert(islas.end(), isla<double>(4,4));
    tombuctu(G1, islas);
    
}