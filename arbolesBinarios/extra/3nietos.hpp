#include "../aBinEnlazada.hpp"

template <typename T>
unsigned nietos(const Abin<T>& A)
{
    return nietosRec(A.raiz(), A);
}

template <typename T>
unsigned nietosRec(typename Abin<T>::nodo n, const Abin<T>& A)
{
    if(n == Abin<T>::NODO_NULO)
        return 0;
    else
    {
        if (valido(n, A))
            return 1 + nietosRec(A.hijoIzqdo(n), A) + nietosRec(A.hijoIzqdo(n), A);
        else 
            return 0 + nietosRec(A.hijoIzqdo(n), A) + nietosRec(A.hijoIzqdo(n), A);
    }
}

template <typename T>
bool valido(typename Abin<T>::nodo n, const Abin<T>& A)
{
    if (A.hijoDrcho(n) != Abin<T>::NODO_NULO && A.hijoIzqdo(n) != Abin<T>::NODO_NULO)
    {
        if(A.hijoDrcho(A.hijoDrcho(n)) != Abin<T>::NODO_NULO && A.hijoDrcho(A.hijoIzqdo(n)) == Abin<T>::NODO_NULO && A.hijoIzqdo(A.hijoDrcho(n)) != Abin<T>::NODO_NULO && A.hijoIzqdo(A.hijoIzqdo(n)) != Abin<T>::NODO_NULO)
            return true;
        if (A.hijoDrcho(A.hijoIzqdo(n)) != Abin<T>::NODO_NULO && A.hijoDrcho(A.hijoDrcho(n)) == Abin<T>::NODO_NULO && A.hijoIzqdo(A.hijoDrcho(n)) != Abin<T>::NODO_NULO && A.hijoIzqdo(A.hijoIzqdo(n)) != Abin<T>::NODO_NULO)
            return true;
        if (A.hijoDrcho(A.hijoDrcho(n)) != Abin<T>::NODO_NULO && A.hijoDrcho(A.hijoIzqdo(n)) != Abin<T>::NODO_NULO && A.hijoIzqdo(A.hijoIzqdo(n)) != Abin<T>::NODO_NULO && A.hijoIzqdo(A.hijoDrcho(n)) == Abin<T>::NODO_NULO)
            return true;
        if (A.hijoDrcho(A.hijoDrcho(n)) != Abin<T>::NODO_NULO && A.hijoDrcho(A.hijoIzqdo(n)) != Abin<T>::NODO_NULO && A.hijoIzqdo(A.hijoDrcho(n)) != Abin<T>::NODO_NULO && A.hijoIzqdo(A.hijoIzqdo(n)) != Abin<T>::NODO_NULO)
            return true;
    }
    return false;
}


    
       