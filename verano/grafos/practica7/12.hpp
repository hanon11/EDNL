#include <iostream>
#include "../../../grafos/alg_grafoPMC.hpp"

template <typename tCoste>
void grecoland(const GrafoP<tCoste>& fobos, const GrafoP<tCoste>& deimos, vector<typename GrafoP<tCoste>::vertice> costerasF,
    vector<typename GrafoP<tCoste>::vertice> costerasD)
{
    GrafoP<tCoste> archipielago(fobos.numVert()+deimos.numVert());
    for(typename GrafoP<tCoste>::vertice i = 0; i < fobos.numVert(); ++i)
    {
        for(typename GrafoP<tCoste>::vertice j = 0; j < fobos.numVert(); ++j)
        {
            archipielago[i][j] = fobos[i][j];
        }
    }

    for(typename GrafoP<tCoste>::vertice i = fobos.numVert(), k = 0; i < fobos.numVert() + deimos.numVert(); ++i, ++k)
    {
        for(typename GrafoP<tCoste>::vertice j = fobos.numVert(), l = 0; j < fobos.numVert() + deimos.numVert(); ++j, ++l)
        {
            archipielago[i][j] = deimos[k][l];
        }
    }
    tCoste min = GrafoP<tCoste>::INFINITO;
    typename GrafoP<tCoste>::vertice mejorFobos; typename GrafoP<tCoste>::vertice mejorDeimos;
    for(int i = 0; i < costerasF.size(); ++i)
    {
        for(int j = 0; j < costerasD.size(); ++j)
        {
            archipielago[costerasF[i]][costerasD[j]+fobos.numVert()] = 0; 
            archipielago[costerasF[i]+fobos.numVert()][costerasD[j]] = 0; 
            tCoste aux = costesMin(archipielago);
            if(aux < min)
            {
                min = aux;
                mejorFobos = costerasF[i];
                mejorDeimos = costerasD[j];
            }
            archipielago[costerasF[i]][costerasD[j]+fobos.numVert()] = GrafoP<tCoste>::INFINITO; 
            archipielago[costerasF[i]+fobos.numVert()][costerasD[j]] = GrafoP<tCoste>::INFINITO; 
        }
    }
    std::cout << "La mejor costera de fobos es: " << mejorFobos << std::endl;
    std::cout << "La mejor costera de deimos es: " << mejorDeimos << std::endl;

}

template <typename tCoste>
tCoste costesMin(const GrafoP<tCoste>& arch)
{
    matriz<tCoste> mCostes(arch.numVert());
    matriz<typename GrafoP<tCoste>::vertice> mVer(arch.numVert());
    mCostes = Floyd(arch, mVer);
    tCoste total = 0;
    for(typename GrafoP<tCoste>::vertice i = 0; i < arch.numVert(); ++i)
    {
        for(typename GrafoP<tCoste>::vertice j = 0; j < arch.numVert(); ++j)
        {
            if(arch[i][i] != GrafoP<tCoste>::INFINITO)
                total += mCostes[i][j];
        }
    }
    return total;
}