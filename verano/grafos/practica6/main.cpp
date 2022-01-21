#include "../../../grafos/alg_grafoPMC.hpp"
#include "../../../grafos/alg_grafo_E-S.hpp"
#include "zuelandia.hpp"
#include <iostream>

int main()
{
    //GrafoP<unsigned > E1("pseudocentro.dat");
    //unsigned diametro = pseudocentro(E1);
    //std::cout << diametro << std::endl;
    //GrafoP<unsigned > E2("otraVezUnGrafo.dat");
    //bool acic = aciclico(E2);
    //if(acic)
      //  std::cout << "Aciclico" << std::endl;
    //else
      //  std::cout << "Ciclico" << std::endl;

    GrafoP<unsigned> E4("5.dat");
    std::cout << E4 << std::endl;
    vector<GrafoP<int>::vertice> ciudad;
    vector<carretera> carreteras;
    carretera carretera1, carretera2;
    carretera1.origen = 0, carretera1.destino = 2;
    carretera2.origen = 1, carretera2.destino = 2;
    //ciudad.insert(ciudad.begin(), 2);
    //ciudad.insert(ciudad.end(), 1);
    //carreteras.insert(carreteras.begin(), carretera1);
    //carreteras.insert(carreteras.end(), carretera2);
    zuelandia(E4, ciudad, carreteras, 2);
} 