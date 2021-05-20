
#include "floydModificado.hpp"
#include <iostream>

template <typename tCoste>
bool aciclico(const GrafoP<tCoste>& G)
{
    typedef typename GrafoP<tCoste>::vertice vertice;
    matriz<vertice> mVertices(G.numVert());
    matriz<tCoste> mCostes = FloydMod(G, mVertices);
    std::cout << mCostes << std::endl;
    bool acicl = true; //parto de que es aciclico hasta que demuestre lo contrario
    for(vertice i = 0; i < G.numVert() && acicl; i++)
    {
        for(vertice j = 0; j < G.numVert() && acicl; j++)
        {
            if(i == j && mCostes[i][j] != GrafoP<tCoste>::INFINITO)
                acicl = false;
        }
    }
    return acicl;
}
