#include "../alg_grafoPMC.hpp"
#include <iostream>

template <typename tCoste>
tCoste pseudocentro(const GrafoP<tCoste>& G)
{
    typedef typename GrafoP<tCoste>::vertice vertice;
    matriz<vertice> mVertices(G.numVert()); //matriz de vertices (para Floyd)
    matriz<tCoste> mCoste = Floyd(G, mVertices); 
    tCoste diametro = GrafoP<tCoste>::INFINITO, o, d;
    vertice pseudo;
    std::cout << mCoste << std::endl;

    for(vertice i = 0; i < G.numVert(); i++)
    {
        o = 0;
        d = 0;
        for(vertice j = 0; j < G.numVert(); j++)
        {
            if(mCoste[i][j] >= o)
            {
                d = o;
                o = mCoste[i][j];
            }
            else if(mCoste[i][j] >= d)
                d = mCoste[i][j];
        }
        if(diametro > o + d)
        {
            diametro = o + d;
            pseudo = i;
        }
    }
    std::cout << "Pseudocentro: " << pseudo << std::endl;
    return diametro;
}