#include <iostream>
#include "../../arbolesBinarios/aBinEnlazada.hpp"

union exp
{ 
    double operando; 
    char operador;
};

template <typename T>
bool esHoja(typename Abin<T>::nodo n, const Abin<T>& A)
{
    return (A.hijoDrcho(n) == Abin<T>::NODO_NULO && A.hijoIzqdo(n) == Abin<T>::NODO_NULO);
}


double expresion(const Abin<exp>& A)
{
    return evaluar(A.raiz(), A);
}


double evaluar(typename Abin<exp>::nodo n, const Abin<exp>& A)
{
    if(esHoja(n, A))
        return A.elemento(n).
}