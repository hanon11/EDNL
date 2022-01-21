#include "agen_E-S.hpp"
#include "aGenEnlazada.hpp"
#include "P3.hpp"
int main()
{
    Agen<int> A;
    std::ifstream fe("agen.dat");
    rellenarAgen(fe, A);
    poda(A, 3);
    imprimirAgen(A);
}