#include "../alg_grafoPMC.hpp"
#include "../alg_grafo_E-S.hpp"
#include "1.hpp"
int main()
{
    GrafoP<unsigned> G1("1.dat");
    std::cout << "El grafo\n" << G1 << std::endl;
    Viaje<unsigned> viaje = calcularViajeCaro(G1); 
    std::cout << "Costes: " << viaje.coste << "\nOrigen: " << viaje.origen << "\nDestino: " << viaje.destino << std::endl;
}
