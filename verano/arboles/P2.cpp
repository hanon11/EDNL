#include <iostream>
#include "../../arbolesBinarios/aBinEnlazada.hpp"
template <typename T>
Abin<T> reflejado(const Abin<T>& a)
{
    Abin<T> r;
    if(!a.arbolVacio())
    {
        r.insertarRaiz(a.elemento(a.raiz()));
        reflejadoRec(a.raiz(), a, r.raiz(), r)
    }
    return r;
}

template <typename T>
bool reflejadoRec(typename Abin<T>::nodo n1, const Abin<T>& a1, typename Abin<T>::nodo n2, const Abin<T>& a2)
{
    if(a1.hijoIzqdo(n1) != Abin<T>::NODO_NULO)
    {
        a2.insertarHijoDrcho(a1.hijoIzqdo(n1));
        reflejadoRec(a1.hijoIzqdo(n1), a1, a2.hijoDrcho(n2), a2)
    }
    if(a1.hijoDrcho(n1) != Abin<T>::NODO_NULO)
    {
        a2.insertarHijoIzqdo(a1.hijoDrcho(n1));
        reflejadoRec(a1.hijoDrcho(n1), a1, a2.hijoIzqdo(n2), a2)
    }
}