#include <iostream>
#include "../alg_grafoPMC.hpp"

struct parte    
{
    int destino, carga;
};

template <typename tCoste>
unsigned cementosZuelandia(const GrafoP<tCoste>& G, vector<parte> recorrido, 
                typename GrafoP<tCoste>::vertice capital)
{
    std::cout << "Antes de Dijkstra: " << G << std::endl;
    vector<typename GrafoP<tCoste>::vertice> vVer;
    vector<tCoste> vCostesIda = Dijkstra(G, capital, vVer);
    vector<tCoste> vCostesVuelta = DijkstraInv(G, capital, vVer);
    std::cout << "Costes ida: " << vCostesIda << std::endl;
    std::cout << "Costes vuelta: " << vCostesVuelta << std::endl;
    unsigned kms = 0;
    for(int i = 0; i < G.numVert(); ++i)
    {
        for(int j = 0; j < recorrido.size(); ++j)
        { 
            if(i != capital && recorrido[j].destino == i && recorrido[j].carga > 0)
                kms = (vCostesIda[i] + vCostesVuelta[i]) * recorrido[j].carga;
        }
    }
    return kms;
}