#include <iostream>
#include "../arbolesBinarios/aBinEnlazada.hpp"

template <typename T>
unsigned ancestros(typename Abin<T>::nodo n, const Abin<T>& A)
{
    if(n == Abin<T>::NODO_NULO)
        return 0;
    else
        return 1 + ancestros(A.padre(n), A);
}

template <typename T>
unsigned sucesores(typename Abin<T>::nodo n, const Abin<T>& A)
{
    if(n == Abin<T>::NODO_NULO)
        return 0;
    else
        return 1 + sucesores(A.hijoDrcho(n), A) + sucesores(A.hijoIzqdo(n), A);
}

template <typename T>
unsigned nostalgicos(const Abin<T>& A)
{
    return nostalgicosRec(A.raiz(), A);
}

template <typename T>
unsigned nostalgicosRec(typename Abin<T>::nodo n, const Abin<T>& A)
{
    if(n == Abin<T>::NODO_NULO)
        return 0;
    else
    {
        if(ancestros(n, A) > sucesores(n, A))
            return 1 + nostalgicosRec(A.hijoDrcho(n), A) + nostalgicosRec(A.hijoIzqdo(n), A);
        else 
            return nostalgicosRec(A.hijoDrcho(n), A) + nostalgicosRec(A.hijoIzqdo(n), A);
    }
}