#include <iostream>
#include <fstream>
#include "../../arbolesBinarios/aBinEnlazada.hpp"
#include "../../arbolesBinarios/aBinE-S.hpp"
#include "1.hpp"
int main ()
{
    Abin<char> A{};
    std::ifstream fe("abin.dat"); // Abrir fichero de entrada.
    rellenarAbin(fe, A); // Desde fichero.
    fe.close(); 

    std::cout << profundidad(A, A.hijoDrcho(A.raiz())) <<  std::endl;
} 
