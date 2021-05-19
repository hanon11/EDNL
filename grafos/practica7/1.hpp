#include "../alg_grafoPMC.hpp"
#include <iostream>

template <typename tCoste>
struct Viaje
{
    tCoste coste;
    typename GrafoP<tCoste>::vertice origen, destino;
};

template <typename tCoste>
Viaje<tCoste> calcularViajeCaro(const GrafoP<tCoste>& G)
{
    Viaje<tCoste> viaje;
    matriz<typename GrafoP<tCoste>::vertice> mV(G.numVert());
    matriz<tCoste> mCostes = FloydMax(G, mV);
    matriz<typename GrafoP<tCoste>::vertice> visitado(G.numVert());
    std::cout << "Despues de Floyd\n" << mCostes;
    viaje.origen = viaje.destino = viaje.coste = 0;
    for(typename GrafoP<tCoste>::vertice v = 0; v < G.numVert(); ++v){
        for(typename GrafoP<tCoste>::vertice w = 0; w < G.numVert(); ++w)
        {
            if(mCostes[v][w] != GrafoP<tCoste>::INFINITO && viaje.coste < mCostes[v][w])
            {
                viaje.origen = v;
                viaje.destino = w;
                viaje.coste = mCostes[v][w];
            }
        }
    }
    return viaje;
}
