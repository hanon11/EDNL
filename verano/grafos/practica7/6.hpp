#include <iostream>
#include "../../../grafos/alg_grafoPMC.hpp"
//4 opciones: todo tren, todo bus, empezar en bus y cambiar a tren, empezar en tren y cambiar a bus
template <typename tCoste>
void viaje(const GrafoP<tCoste>& bus, const GrafoP<tCoste>& tren, typename GrafoP<tCoste>::vertice ciudad)
{
    unsigned n = bus.numVert();
    matriz<typename GrafoP<tCoste>::vertice> mV(n);
    matriz<tCoste> B = Floyd(bus, mV);
    matriz<tCoste> T = Floyd(tren, mV);
    matriz<tCoste> mMin(n);
    for(typename GrafoP<tCoste>::vertice i = 0; i < n; ++i)
    {
        for(typename GrafoP<tCoste>::vertice j = 0; j < n; ++j)
        {
            mMin[i][j] = std::min(B[i][j], std::min(T[i][j], std::min((B[i][ciudad]+T[ciudad][j]), (T[i][ciudad]+B[ciudad][j]))));
        }
    }
}