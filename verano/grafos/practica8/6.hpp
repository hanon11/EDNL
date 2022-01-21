#include <iostream>
#include "../../../grafos/alg_grafoPMC.hpp"

template <typename tCoste>
void canales(const GrafoP<tCoste>& kms, const GrafoP<tCoste>& caudal, double subvencion, double coste)
{
    typedef typename GrafoP<tCoste>::vertice vertice;
    GrafoP<double> total(kms.numVert());
    for(vertice i = 0; i < kms.numVert(); i++)
    {
        for(vertice j = 0; j < kms.numVert(); j++)
        {
            if(kms[i][j] != GrafoP<tCoste>::INFINITO && caudal[i][j] != GrafoP<tCoste>::INFINITO)
                total[i][j] = kms[i][j]*coste - caudal[i][j]*subvencion;
        }
    }
    GrafoP<double> final = Prim(total);
    std::cout << final << std::endl;
}