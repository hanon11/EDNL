#include <iostream>
#include "../alg_grafoPMC.hpp"

template <typename tCoste>
void origenDestino(const GrafoP<tCoste>& tren, const GrafoP<tCoste>& bus,
            typename GrafoP<tCoste>::vertice origen, typename GrafoP<tCoste>::vertice destino,
            typename GrafoP<tCoste>::vertice cambio1, typename GrafoP<tCoste>::vertice cambio2)
{
    vector<typename GrafoP<tCoste>::vertice> vVer;
    vector<tCoste> mCosteTren = Dijkstra(tren, origen, vVer);
    vector<tCoste> mCosteBus = DijkstraInv(bus, destino, vVer);
    std::cout << mCosteTren << std::endl;
    std::cout << mCosteBus << std::endl;
    tCoste min = std::min(mCosteTren[cambio1]+mCosteBus[cambio1], mCosteTren[cambio2]+mCosteBus[cambio2]);
    std::cout << "El coste de la ruta es: " << min << std::endl;
    if(min == mCosteTren[cambio1]+mCosteBus[cambio1])
      std::cout << "La ruta a seguir es: " << origen << ", " << cambio1 << ", " << destino << std::endl;
    else
      std::cout << "La ruta a seguir es: " << origen << ", " << cambio2 << ", " << destino << std::endl;
}
