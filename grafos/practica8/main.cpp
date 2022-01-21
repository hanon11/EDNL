#include <iostream>
#include "../alg_grafo_E-S.hpp"
#include "../grafoMA.hpp"
#include "1.hpp"

int main()
{
    Grafo G1("1.dat");
    std::cout << G1;
    //tombuctu2(G1, islas);
    /*GrafoP<unsigned> G5("5.dat");
    reteuni3(G5);
    GrafoP<double> costes("5.dat"), G6("5.dat");
    canales(G6, costes, 2.1, 5.4);
    vector<ciudad> Fobos, Deimos;
    vector<vertice> costerasFobos, costerasDeimos;
    Fobos.push_back(ciudad(0,0));
    Fobos.push_back(ciudad(0,2));
    Fobos.push_back(ciudad(2,1));
    Deimos.push_back(ciudad(4,4));
    Deimos.push_back(ciudad(5,7));
    costerasFobos.push_back(2);
    costerasDeimos.push_back(0);
    grecoland(Fobos, Deimos, costerasFobos, costerasDeimos, 0, 4);*/
}