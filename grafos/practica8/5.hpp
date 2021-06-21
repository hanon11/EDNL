#include <iostream>
#include "../alg_grafoPMC.hpp"
#include "../alg_grafoMA.hpp"

template <typename tCoste>
void reteuni3(const GrafoP<tCoste>& pais)
{
    GrafoP<tCoste> costes = Kruskall(pais);
    std::cout << costes << std::endl;
    tCoste total = 0;
    for(std::size_t i = 0; i < pais.numVert()-1; ++i)
    {
        for(std::size_t j = i+1; j < pais.numVert(); ++j)
        {
            if(costes[i][j] != GrafoP<tCoste>::INFINITO)
                total += costes[i][j];
        }
    }
    std::cout << total << std::endl;
}