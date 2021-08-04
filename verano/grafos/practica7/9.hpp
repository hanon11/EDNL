#include <iostream>
#include "../../../grafos/alg_grafoPMC.hpp"

template <typename tCoste>
void viaje(const GrafoP<tCoste>& tren, const GrafoP<tCoste>& bus, typename GrafoP<tCoste>::vertice origen,
    typename GrafoP<tCoste>::vertice destino, double precioTaxi)
{
    GrafoP<tCoste> G(tren.numVert()*2);
    for(typename GrafoP<tCoste>::vertice i = 0; i < tren.numVert(); i++)
    {
        for(typename GrafoP<tCoste>::vertice j = 0; j < tren.numVert(); j++)
        {
            G[i][j] = tren[i][j];
        }
    }

    for(typename GrafoP<tCoste>::vertice i = tren.numVert(), k = 0; i < bus.numVert() + tren.numVert(); i++, k++)
    {
        for(typename GrafoP<tCoste>::vertice j = tren.numVert(), l = 0; j < bus.numVert() + tren.numVert(); j++, l++)
        {
            G[i][j] = bus[k][l];
        }
    }
    for(typename GrafoP<tCoste>::vertice i = 0; i < tren.numVert(); i++)
    {
        for(typename GrafoP<tCoste>::vertice j = tren.numVert(); j < bus.numVert() + tren.numVert(); j++)
        {
            if(i != j - tren.numVert())
                G[i][j] = GrafoP<tCoste>::INFINITO;
            else
                G[i][j] = precioTaxi;
        }
    }
    for(typename GrafoP<tCoste>::vertice i = tren.numVert(); i < bus.numVert() + tren.numVert(); i++)
    {
        for(typename GrafoP<tCoste>::vertice j = 0; j < tren.numVert(); j++)
        {
            if(i-tren.numVert() != j)
                G[i][j] = GrafoP<tCoste>::INFINITO;
            else
                G[i][j] = precioTaxi;
        }
    }

    vector<typename GrafoP<tCoste>::vertice> vVer;
    vector<tCoste> mCostesTren = Dijkstra(G, origen, vVer);
    vector<tCoste> mCostesBus = Dijkstra(G, origen+bus.numVert(), vVer);
    tCoste minimo = std::min(mCostesTren[destino], mCostesBus[destino]);
    minimo = std::min(minimo, std::min(mCostesTren[destino+bus.numVert()], mCostesBus[destino+bus.numVert()]));
    std::cout << "El minimo coste es: " << minimo << '\n';
}