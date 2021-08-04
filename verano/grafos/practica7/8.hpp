#include <iostream>
#include "../../../grafos/alg_grafoPMC.hpp"

template <typename tCoste>
void unSoloTransbordo(const GrafoP<tCoste>& tren, const GrafoP<tCoste>& bus, typename GrafoP<tCoste>::vertice origen,
    typename GrafoP<tCoste>::vertice destino)
{
    vector<typename GrafoP<tCoste>::vertice> vVer;
    vector<tCoste> DT = Dijkstra(tren, origen, vVer);
    vector<tCoste> DB = Dijkstra(bus, origen, vVer);
    vector<tCoste> DIT = DijkstraInv(tren, destino, vVer);
    vector<tCoste> DIB = DijkstraInv(bus, destino, vVer);
    //costes directos
    tCoste minimo = std::min(DT[destino], DB[destino]);
    for(typename GrafoP<tCoste>::vertice i = 0; i < DT.size(); i++) //miro ahora haciendo trasbordo
    {
        if(i != origen || i != destino)
            minimo = std::min(minimo, std::min(suma(DT[i],DIB[i]), suma(DB[i], DIT[i])));
    }
    std::cout << "El coste minimo es: " << minimo << std::endl;
}