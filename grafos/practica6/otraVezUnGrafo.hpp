#include "../alg_grafoPMC.hpp"
#include <iostream>

template <typename tCoste>
bool aciclico(const GrafoP<tCoste>& G)
{
    typedef typename GrafoP<tCoste>::vertice vertice;
    matriz<vertice> mVertices(G.numVert());
    matriz<tCoste> mCostes = Floyd(G, mVertices);
    std::cout << mCostes << std::endl;
    for(vertice i = 0; i < G.numVert(); i++)
    {
        for(vertice j = 0; j < G.numVert(); j++)
        {
            if(mCostes[i][j] == GrafoP<tCoste>::INFINITO) //en cuanto encuentre un infinito ya es aciclico
                return true;
        }
    }
    return false;
}