#include <iostream>
#include "../../arbolesBinarios/aBinEnlazada.hpp"
template <typename T>
unsigned numNodos(const Abin<T>& A)
{
    return numNodosRec(A, A.raiz());
}

template <typename T>
unsigned numNodosRec(const Abin<T>& A, typename Abin<T>::nodo n)
{
    if(n == Abin<T>::NODO_NULO)
        return 0;
    else
        return 1 + numNodosRec(A, A.hijoDrcho(n)) + numNodosRec(A, A.hijoIzqdo(n));
}

template <typename T>
unsigned altura(const Abin<T>& A)
{
    return alturaRec(A, A.raiz());
}

template <typename T>
unsigned alturaRec(const Abin<T>& A, typename Abin<T>::nodo n)
{
    if(n == Abin<T>::NODO_NULO)
        return -1;
    else
        return 1 + std::max(alturaRec(A, A.hijoDrcho(n)), alturaRec(A, A.hijoIzqdo(n)));
}


template <typename T>
unsigned profundidad(const Abin<T>& A, typename Abin<T>::nodo n)
{
    int profundidad = 0;

    while (n != A.raiz())
    {
        profundidad++;
        n = A.padre(n);
    }

    return profundidad;
}
