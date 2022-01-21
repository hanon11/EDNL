#include <iostream>
#include "../arbolesBinarios/aBinEnlazada.hpp"
#include "../arbolesBinarios/aBinE-S.hpp"
#include "../arbolesBinariosBusqueda/aBinE-S.hpp"
#include "../arbolesBinariosBusqueda/Abb.hpp"
#include "../grafos/alg_grafoPMC.hpp"
#include "../grafos/alg_grafo_E-S.hpp"
#include "infimoSupremo.hpp"
#include "rebeldes.hpp"
int main()
{
    Abin<int> A;
    rellenarAbin(A, -1);
    std::cout << rebeldes(A);
}