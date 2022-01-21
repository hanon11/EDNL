#include <iostream>
#include "../arbolesBinarios/aBinEnlazada.hpp"

template <typename T>
bool nietos(typename Abin<T>::nodo n, const Abin<T>& A)
{
    if(A.hijoIzqdo(A.hijoIzqdo(n)) != Abin<T>::NODO_NULO && 
       A.hijoIzqdo(A.hijoDrcho(n)) != Abin<T>::NODO_NULO &&
       A.hijoDrcho(A.hijoIzqdo(n)) != Abin<T>::NODO_NULO &&
       A.hijoDrcho(A.hijoDrcho(n)) == Abin<T>::NODO_NULO)
        return true;
    if(A.hijoIzqdo(A.hijoIzqdo(n)) != Abin<T>::NODO_NULO && 
       A.hijoIzqdo(A.hijoDrcho(n)) != Abin<T>::NODO_NULO &&
       A.hijoDrcho(A.hijoIzqdo(n)) == Abin<T>::NODO_NULO &&
       A.hijoDrcho(A.hijoDrcho(n)) != Abin<T>::NODO_NULO)
        return true;
    if(A.hijoIzqdo(A.hijoIzqdo(n)) != Abin<T>::NODO_NULO && 
       A.hijoIzqdo(A.hijoDrcho(n)) == Abin<T>::NODO_NULO &&
       A.hijoDrcho(A.hijoIzqdo(n)) != Abin<T>::NODO_NULO &&
       A.hijoDrcho(A.hijoDrcho(n)) != Abin<T>::NODO_NULO)
        return true;
    if(A.hijoIzqdo(A.hijoIzqdo(n)) == Abin<T>::NODO_NULO && 
       A.hijoIzqdo(A.hijoDrcho(n)) != Abin<T>::NODO_NULO &&
       A.hijoDrcho(A.hijoIzqdo(n)) != Abin<T>::NODO_NULO &&
       A.hijoDrcho(A.hijoDrcho(n)) != Abin<T>::NODO_NULO)
        return true;
    return false;
}

template <typename T>
unsigned tresNietos(const Abin<T>& A)
{
    if(A.arbolVacio())
        return 0;
    else
        return tresNietosRec(A.raiz(), A);
}

template <typename T>
unsigned tresNietosRec(typename Abin<T>::nodo n, const Abin<T>& A)
{
    if(A.hijoIzqdo(n) == Abin<T>::NODO_NULO || A.hijoDrcho(n) == Abin<T>::NODO_NULO)
        return 0;
    
    if(nietos(n, A))
        return 1 + tresNietosRec(A.hijoDrcho(n), A) + tresNietosRec(A.hijoIzqdo(n), A);
    else
        return 0 + tresNietosRec(A.hijoDrcho(n), A) + tresNietosRec(A.hijoIzqdo(n), A); 

}