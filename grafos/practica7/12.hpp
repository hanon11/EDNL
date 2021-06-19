#include <iostream>
#include "../alg_grafoPMC.hpp"

template <typename tCoste>
void grecoland(const GrafoP<tCoste>& fobos, const GrafoP<tCoste>& deimos, vector<typename GrafoP<tCoste>::vertice> costerasFobos, 
        vector<typename GrafoP<tCoste>::vertice> costerasDeimos)
{
    
    matriz<typename GrafoP<tCoste>::vertice> vVerF, vVerD;
    matriz<tCoste> mCostesF = Floyd(fobos, vVerF);
    matriz<tCoste> mCostesD = Floyd(deimos, vVerD);
    //std::cout << mCostesF << std::endl;
    //std::cout << mCostesD << std::endl;
    tCoste minFobos = GrafoP<tCoste>::INFINITO, minDeimos = GrafoP<tCoste>::INFINITO;
    typename GrafoP<tCoste>::vertice ciudadCosteraDeimos, ciudadCosteraFobos;
    tCoste aux = 0;
    for(typename GrafoP<tCoste>::vertice i = 0; i < costerasDeimos.size(); ++i)
    {
        for(typename GrafoP<tCoste>::vertice j = 0; j < deimos.numVert(); ++j)
        {
            if(mCostesD[costerasDeimos[i]][j] != GrafoP<tCoste>::INFINITO)
                aux += mCostesD[costerasDeimos[i]][j];  
            if(mCostesD[j][costerasDeimos[i]] != GrafoP<tCoste>::INFINITO)
                aux += mCostesD[j][costerasDeimos[i]];
        }
        if(aux < minDeimos)
        {
            minDeimos = aux;
            ciudadCosteraDeimos = costerasDeimos[i];
        }
        aux = 0;
    }

    aux = 0;
    for(typename GrafoP<tCoste>::vertice i = 0; i < costerasFobos.size(); ++i)
    {
        for(typename GrafoP<tCoste>::vertice j = 0; j < fobos.numVert(); ++j)
        {
            if(mCostesF[costerasFobos[i]][j] != GrafoP<tCoste>::INFINITO)
                aux += mCostesF[costerasFobos[i]][j];
            if(mCostesF[j][costerasFobos[i]] != GrafoP<tCoste>::INFINITO)
                aux += mCostesF[j][costerasFobos[i]];
        }
        if(aux < minFobos)
        {
            minFobos = aux;
            ciudadCosteraFobos = costerasFobos[i];
        }
        aux = 0;
    }
    std::cout << "La mejor ciudad costera de Fobos es: " << ciudadCosteraFobos << " con coste " << minFobos << std::endl;
    std::cout << "La mejor ciudad costera de Deimos es: " << ciudadCosteraDeimos << " con coste " << minDeimos << std::endl;
    
}