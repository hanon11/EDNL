#include <iostream>
#include "../alg_grafoMA.hpp"
#include "../alg_grafoPMC.hpp"

template <typename tCoste>
void canales(const GrafoP<tCoste>& ciudades, const GrafoP<tCoste>& caudales, double subvencion, double precioKM)
{
    GrafoP<double> total(ciudades.numVert());

    for(int i = 0; i < ciudades.numVert(); ++i)
    {
        for(int j = 0; j < ciudades.numVert(); ++j)
        {
            if(ciudades[i][j] != GrafoP<tCoste>::INFINITO && caudales[i][j] != GrafoP<tCoste>::INFINITO)
                total[i][j] = suma(ciudades[i][j]*precioKM, -caudales[i][j]*subvencion);
        }
    }

    std::cout << Kruskall(total) << std::endl;

}