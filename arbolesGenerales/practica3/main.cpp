#include <iostream>
#include <fstream>
#include "../agen_E-S.hpp"
#include "ejercicios.hpp"
const char fin = '#';

int main ()
{
    Agen<char> A, B;
    cout << "*** Lectura del árbol A ***\n";
    rellenarAgen(A, fin); // Desde std::cin
    std::ofstream fs("agen.dat"); // Abrir fichero de salida.
    imprimirAgen(fs, A, fin); // En fichero.
    fs.close();
    cout << "\n*** Árbol A guardado en fichero agen.dat ***\n";
    cout << "\n*** Lectura de árbol B de agen.dat ***\n";
    std::ifstream fe("agen.dat"); // Abrir fichero de entrada.
    rellenarAgen(fe, B); // Desde fichero.
    fe.close();
    cout << "\n*** Mostrar árbol B ***\n";
    imprimirAgen(B); // En std::cout
    cout << "El desequilibrio del arbol es: " << desequilibrio(B) << endl;
} 
