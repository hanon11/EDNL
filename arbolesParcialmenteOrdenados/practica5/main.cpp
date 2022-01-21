#include <iostream>
#include "../../arbolesGenerales/aGenEnlazada.hpp"
#include "../../arbolesGenerales/agen_E-S.hpp"
#include "ejercicios.hpp"
int main()
{
    Agen<int> A;
    rellenarAgen(A, -1);
    if(ternario(A))
        std::cout << "SI";

}