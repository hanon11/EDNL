#include <iostream>
#include "../alg_grafoPMC.hpp"

template <typename tCoste>
vector<int> viajeroAlergico(const GrafoP<tCoste>& carretera, const GrafoP<tCoste>& tren, 
            const GrafoP<tCoste>& avion, int alergia, typename GrafoP<tCoste>::vertice salida, tCoste dinero)
{
    //0 carretera, 1 tren y 2 avion
    vector<int> puedeViajar(carretera.numVert(), 0); //uso 0 como false, un vector de booleanos me imprime - cuando es true
    vector<tCoste> vCostes;
    switch(alergia)
    {
        case 0: //alergico a carretera
            vCostes = calculoViaje(tren, avion, salida);
            break;
        case 1: //alergico a tren
            vCostes = calculoViaje(carretera, avion, salida);
            break;
        case 2: //alergico a avion
            vCostes = calculoViaje(tren, carretera, salida);
            break;
    }
    
    for(int i = 0; i < vCostes.size(); ++i)
    {
        if(vCostes[i] <= dinero)
        {
            puedeViajar[i] = 1; // si puede viajar tiene un 1
            dinero -= vCostes[i];
        }
    }
    return puedeViajar;
}

template <typename tCoste>
vector<tCoste> calculoViaje(const GrafoP<tCoste>& medio1, const GrafoP<tCoste>& medio2, 
            typename GrafoP<tCoste>::vertice salida)
{
    GrafoP<tCoste> G = medio1;
    for(int i = 0; i < G.numVert(); ++i)
    {
        for(int j = 0; j < G.numVert(); ++j)
        {
            G[i][j] = std::min(G[i][j], medio2[i][j]);
        }
    }
    vector<typename GrafoP<tCoste>::vertice> vVer;
    vector<tCoste> vCostes = Dijkstra(G, salida, vVer);
    std::cout << vCostes << std::endl;
    return vCostes;
}