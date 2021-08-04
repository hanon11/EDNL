#include <iostream>
#include "../../../grafos/alg_grafoPMC.hpp"

struct Puente
{
    unsigned origen, destino;
};

template <typename tCoste>
void tresIslas(const GrafoP<tCoste>& isla1, const GrafoP<tCoste>& isla2, const GrafoP<tCoste>& isla3,
    vector<Puente> puentes)
{
    GrafoP<tCoste> archipielago(isla1.numVert() + isla2.numVert() + isla3.numVert());
    for(typename GrafoP<tCoste>::vertice i = 0; i < isla1.numVert(); ++i)
    {
        for(typename GrafoP<tCoste>::vertice j = 0; j < isla1.numVert(); ++j)
        {
            archipielago[i][j] = isla1[i][j];
        }
    }
    for(typename GrafoP<tCoste>::vertice i = isla1.numVert(), k = 0; i < isla1.numVert() + isla2.numVert(); ++i, ++k)
    {
        for(typename GrafoP<tCoste>::vertice j = isla1.numVert(), l = 0; j < isla1.numVert() + isla2.numVert(); ++j, ++l)
        {
            archipielago[i][j] = isla2[k][l];
        }
    }
    for(typename GrafoP<tCoste>::vertice i = isla1.numVert() + isla2.numVert(), k = 0; i < isla1.numVert() + isla2.numVert() + isla3.numVert(); ++i, ++k)
    {
        for(typename GrafoP<tCoste>::vertice j = isla1.numVert() + isla2.numVert(), l = 0; j < isla1.numVert() + isla2.numVert() + isla3.numVert(); ++j, ++l)
        {
            archipielago[i][j] = isla3[k][l];
        }
    }
    for(int i = 0; i < puentes.size(); ++i)
    {
        archipielago[puentes[i].origen][puentes[i].destino] = 0;
        archipielago[puentes[i].destino][puentes[i].origen] = 0;
    }
    matriz<typename GrafoP<tCoste>::vertice> mVer(isla1.numVert() + isla2.numVert() + isla3.numVert());
    matriz<tCoste> mCostes = Floyd(archipielago, mVer);
    std::cout << mCostes << std::endl;
}
