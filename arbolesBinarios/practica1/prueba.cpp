#include "../aBinE-S.hpp"
#include "../aBinEnlazada.hpp"
#include "ejercicios.hpp"
#include <iostream>
#include <fstream>

int main(){

    Abin<char> A;

    std::cout << "**LECTURA DE ARBOL BINARIO FICHERO DE DATOS**" << std::endl;
    std::ifstream fe("abin.dat"); //abre fichero de entrada
    rellenarAbin(fe, A);
    fe.close();

    std::cout << "MOSTRAR ARBOL BINARIO B" << std::endl;
    imprimirAbin(A);

    std::cout << "El arbol tiene " << numNodos(A) << " nodos "<< std::endl;
    std::cout << "La altura del arbol es " << altura(A) << std::endl;
    std::cout << "La profundidad del arbol es " << profundidad(A.hijoDrcho(A.raiz()), A) << std::endl;
}
