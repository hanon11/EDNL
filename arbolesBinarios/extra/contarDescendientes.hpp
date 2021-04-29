#include "../aBinEnlazada.hpp"

template <typename T>
unsigned numNodos_Rec(typename Abin<T>::nodo n, const Abin<T>& A)
{
    if(n == Abin<T>::NODO_NULO)
        return 0;
    else
        return 1 + numNodos_Rec(A.hijoDrcho(n), A) + numNodos_Rec(A.hijoIzqdo(n), A);
}

template <typename T>
unsigned descendientesRec(typename Abin<T>::nodo n, const Abin<T>& A)
{
    if(n == Abin<T>::NODO_NULO)
        return 0;
    if((numNodos_Rec(A.hijoIzqdo(n), A) + numNodos_Rec(A.hijoDrcho(n), A)) == 4)
        return 1 + descendientesRec(A.hijoDrcho(n), A) + descendientesRec(A.hijoIzqdo(n), A);
    else
        return descendientesRec(A.hijoDrcho(n), A) + descendientesRec(A.hijoIzqdo(n), A);
}

template <typename T>
unsigned descendientes(const Abin<T>& A)
{
    return descendientesRec(A.raiz(), A);
}