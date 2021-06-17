#include <iostream>
#include "../alg_grafoPMC.hpp"

template <typename tCoste>
struct puente
{
    typename GrafoP<tCoste>::vertice ciudad1, ciudad2;
};


template <typename tCoste>
void calculoHuries(const GrafoP<tCoste>& isla1, const GrafoP<tCoste>& isla2, const GrafoP<tCoste>& isla3, vector<puente<tCoste> > puentes)
{
    //el uso de puentes es gratis( = 0 ) 
    GrafoP<tCoste> archipielago(isla1.numVert() + isla2.numVert() + isla3.numVert());
    //isla1     -       -
    //-       isla2     -
    //-         -       isla3
    for(typename GrafoP<tCoste>::vertice i = 0; i < isla1.numVert(); i++)
    {
        for(typename GrafoP<tCoste>::vertice j = 0; j < isla1.numVert(); j++)
        {
            archipielago[i][j] = isla1[i][j];
        }
    }

    for(typename GrafoP<tCoste>::vertice i = isla1.numVert(), k = 0; i < isla1.numVert()+isla2.numVert(); i++, k++)
    {
        for(typename GrafoP<tCoste>::vertice j = isla1.numVert(), l = 0; j < isla1.numVert()+isla2.numVert(); j++, l++)
        {
            archipielago[i][j] = isla2[k][l];
        }
    }

    for(typename GrafoP<tCoste>::vertice i = isla1.numVert()+isla2.numVert(), k = 0; i < isla1.numVert()+isla2.numVert()+isla3.numVert(); i++, k++)
    {
        for(typename GrafoP<tCoste>::vertice j = isla1.numVert()+isla2.numVert(), l = 0; j < isla1.numVert()+isla2.numVert()+isla3.numVert(); j++, l++)
        {
            archipielago[i][j] = isla3[k][l];
        }
    }

    for(size_t i = 0; i < puentes.size(); i++)
    {
        archipielago[puentes[i].ciudad1][puentes[i].ciudad2] = 0;
    }
    matriz<typename GrafoP<tCoste>::vertice> mVer;
    matriz<tCoste> mCostes = Floyd(archipielago, mVer);

    std::cout << mCostes << std::endl;

    
}