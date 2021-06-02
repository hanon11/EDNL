#include <iostream>
#include "../alg_grafoPMC.hpp"
template <typename tCoste>
vector<double> distribucion(GrafoP<double>::vertice origen, unsigned cantidad, GrafoP<tCoste> G, 
                vector<unsigned> almacenamiento, vector<double> porcentajes)
{
    typedef typename GrafoP<tCoste>::vertice vertice;
    for(vertice i = 0; i < G.numVert(); i++)
    {
        for(vertice j = 0; j < G.numVert(); j++)
        {
            if(G[i][j] != GrafoP<tCoste>::INFINITO)
                G[i][j] *= 1 - porcentajes[j]/100;
        }
    }
    vector<vertice> vVer;
    vector<tCoste> costes = Dijkstra(G, origen, vVer);
    std::cout << "Costes minimos: " << costes << std::endl;
    vector<double> total(G.numVert(), 0);
    while(cantidad > 0)
    {
        tCoste min = GrafoP<tCoste>::INFINITO;  
        vertice ciudad = origen;
        for(vertice i = 0; i < G.numVert(); i++)
        {
            if(i != ciudad && costes[i] < min && total[i] == 0 && almacenamiento[i] > 0)
            {
                min = costes[i];
                ciudad = i;
            }
        }
        if(almacenamiento[ciudad] < cantidad)
        {
            total[ciudad] = almacenamiento[ciudad];
            cantidad -= almacenamiento[ciudad];
        }
        else
        {
            total[ciudad] = cantidad;
            cantidad = 0;
        }
    }
    std::cout << total << std::endl;
    return total;
}