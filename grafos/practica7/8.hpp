#include <iostream>
#include "../alg_grafoPMC.hpp"
template <typename tCoste>
void unSoloTrasbordo(const GrafoP<tCoste>& tren, const GrafoP<tCoste>& bus,
            typename GrafoP<tCoste>::vertice origen, typename GrafoP<tCoste>::vertice destino)
{
    //hay 4 opciones: todo en tren, todo en bus, empezar en bus y terminar en tren y
    //empezar en tren y terminar en bus
    vector<typename GrafoP<tCoste>::vertice> vVer(tren.numVert());
    vector<tCoste> costeTren = Dijkstra(tren, origen, vVer);
    vector<tCoste> costeBus = Dijkstra(bus, origen, vVer);
    vector<tCoste> costeTrenInv = DijkstraInv(tren, destino, vVer);
    vector<tCoste> costeBusInv = DijkstraInv(bus, destino, vVer);
    std::cout << costeBus << '\n';
    std::cout << costeTren << '\n';
    std::cout << costeBusInv << '\n';
    std::cout << costeTrenInv << '\n';
    //me quedo con el minimo de ir todo en bus o todo en tren
    tCoste minimo = std::min(costeTren[destino], costeBus[destino]);
    for (typename GrafoP<tCoste>::vertice i = 0; i < costeTren.size(); i++) //miro ahora haciendo trasbordo
    {
        if(i != origen || i != destino)
            minimo = std::min(minimo, std::min(suma(costeTren[i],costeBusInv[i]), suma(costeBus[i],costeTrenInv[i])));
    }
    std::cout << "El precio minimo del viaje es: " << minimo << '\n';
}
