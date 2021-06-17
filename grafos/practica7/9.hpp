#include <iostream>
#include "../alg_grafoPMC.hpp"
template <typename tCoste>
void calculaCamino(const GrafoP<tCoste>& tren, const GrafoP<tCoste>& bus,
            typename GrafoP<tCoste>::vertice origen, typename GrafoP<tCoste>::vertice destino,
            double costeTaxi)
{
    GrafoP<tCoste> costes(tren.numVert()+tren.numVert());
    for (size_t i = 0; i < tren.numVert(); i++)
    {
        for (size_t j = 0; j < tren.numVert(); j++)
        {
            costes[i][j] = tren[i][j];
        }
    }
    for (size_t i = bus.numVert(), k = 0; i < bus.numVert()+bus.numVert(); i++, k++)
    {
        for (size_t j = bus.numVert(), l = 0; j < bus.numVert()+bus.numVert(); j++, l++)
        {
            costes[i][j] = bus[k][l];
        }
    }
    for (size_t i = bus.numVert(); i < bus.numVert()+bus.numVert(); i++)
    {
        for (size_t j = 0; j < bus.numVert(); j++)
        {
            if(i - bus.numVert() != j)
                costes[i][j] = GrafoP<tCoste>::INFINITO;
            else
                costes[i][j] = costeTaxi;
        }
    }
    for (size_t i = 0; i < bus.numVert(); i++)
    {
        for (size_t j = bus.numVert(); j < bus.numVert()+bus.numVert(); j++)
        {
            if(i != j - bus.numVert())
                costes[i][j] = GrafoP<tCoste>::INFINITO;
            else
                costes[i][j] = costeTaxi;
        }
    }

    vector<typename GrafoP<tCoste>::vertice> vVer;
    vector<tCoste> mCostesTren = Dijkstra(costes, origen, vVer);
    vector<tCoste> mCostesBus = Dijkstra(costes, origen+bus.numVert(), vVer);
    tCoste minimo = std::min(mCostesTren[destino], mCostesBus[destino]);
    minimo = std::min(minimo, std::min(mCostesTren[destino+bus.numVert()], mCostesBus[destino+bus.numVert()]));
    std::cout << "El minimo coste es: " << minimo << '\n';
}
