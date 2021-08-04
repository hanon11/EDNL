#include <iostream>
#include "../../../grafos/alg_grafoPMC.hpp"

template <typename tCoste>
void origenDestino(const GrafoP<tCoste>& tren, const GrafoP<tCoste>& bus, typename GrafoP<tCoste>::vertice origen,
    typename GrafoP<tCoste>::vertice destino, typename GrafoP<tCoste>::vertice cambio1, typename GrafoP<tCoste>::vertice cambio2)
{
    
    unsigned n = tren.numVert();
    vector<typename GrafoP<tCoste>::vertice> vVerD(n);
    vector<typename GrafoP<tCoste>::vertice> vVerDI(n);
    vector<tCoste> D = Dijkstra(tren, origen, vVerDI);
    vector<tCoste> DI = DijkstraInv(bus, destino, vVerDI);
    if(D[cambio1]+DI[cambio1] <= D[cambio2]+DI[cambio2])
    {
        std::cout << "Coste del camino: " << D[cambio1]+DI[cambio1] << std::endl;
    }
    else
    {
        std::cout << "Coste del camino: " << D[cambio2]+DI[cambio2] << std::endl;
    }
}