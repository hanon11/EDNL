#include "aGenEnlazada.hpp"
#include <cmath>
#include <algorithm>


template <typename tCoste>
unsigned numHijos(typename Agen<tCoste>::nodo n, const Agen<tCoste>& A)
{
    unsigned nHijos = 0;
    typename Agen<tCoste>::nodo hijo = A.hijoIzqdo(n);
    while(hijo != Agen<tCoste>::NODO_NULO)
    {
        nHijos++;
        hijo = A.hermDrcho(hijo);
    }
    return nHijos;
}

template <typename tCoste>
unsigned grado(const Agen<tCoste>& A)
{
    return gradoRec(A.raiz(), A);
}

template <typename tCoste>
unsigned gradoRec(typename Agen<tCoste>::nodo n, const Agen<tCoste>& A)
{
    if(n == Agen<tCoste>::NODO_NULO)
        return 0;
    else 
    {
        unsigned nHijos = numHijos(n, A);
        typename Agen<tCoste>::nodo hijo = A.hijoIzqdo(n);
        while(hijo != Agen<tCoste>::NODO_NULO)
        {
            nHijos = std::max(nHijos, gradoRec(hijo, A));
            hijo = A.hermDrcho(hijo);
        }
        return nHijos;
    }
}



template <typename tCoste>
unsigned prof(typename Agen<tCoste>::nodo n, const Agen<tCoste>& A)
{
    unsigned profundidad = 0;
    typename Agen<tCoste>::nodo nodo = n;
    while(nodo != A.raiz())
    {
        profundidad++;
        nodo = A.padre(nodo);
    }
    return profundidad;
}

template <typename T>
unsigned desequilibrio(const Agen<T>& A)
{
    return desequilibrioRec(A.raiz(), A);
}

template <typename T>
unsigned altura(typename Agen<T>::nodo n, const Agen<T>& A)
{
    if(n == Agen<T>::NODO_NULO)
        return -1;
    else
    {
        typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
        unsigned alt = 0;
        while(hijo != Agen<T>::NODO_NULO)
        {
            alt = std::max(alt, altura(hijo, A));
            hijo = A.hermDrcho(hijo);
        }
        return 1 + alt;
    }
}

template <typename T>
unsigned alturaMin(typename Agen<T>::nodo n, const Agen<T>& A)
{
    if(n == Agen<T>::NODO_NULO)
        return -1;
    else
    {
        typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
        unsigned alt = INT_MAX;
        while(hijo != Agen<T>::NODO_NULO)
        {
            alt = std::min(alt, alturaMin(hijo, A));
            hijo = A.hermDrcho(hijo);
        }
        return 1 + alt;
    }
}


template <typename T>
unsigned desequilibrioRec(typename Agen<T>::nodo n, const Agen<T>& A)
{
    if(n == Agen<T>::NODO_NULO)
        return 0;
    else
    {
        typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
        unsigned desMax = 0;
        unsigned desNodo = std::abs(altura(n, A) - alturaMin(n, A));
        while(hijo != Agen<T>::NODO_NULO)
        {
            desMax = std::max(desNodo, desequilibrioRec(hijo, A));
            hijo = A.hermDrcho(hijo);
        }
        return desMax;
    }
}

void borrarDescendencia(Agen<int>::nodo n, Agen<int>& A)
{
    Agen<int>::nodo hijo = A.hijoIzqdo(n);

    if(n != Agen<int>::NODO_NULO)
    {
        while(hijo != Agen<int>::NODO_NULO && A.hijoIzqdo(hijo) == Agen<int>::NODO_NULO)
        {
            A.eliminarHijoIzqdo(n);
            hijo = A.hijoIzqdo(n);
        }
        if(A.hijoIzqdo(n) != Agen<int>::NODO_NULO)
        {
            borrarDescendencia(A.hijoIzqdo(n), A);
            borrarDescendencia(n, A);
        }
    }
}

void podaRec(Agen<int>::nodo n, Agen<int>& A, int x)
{
    if(n != Agen<int>::NODO_NULO)
    {
        if(A.elemento(n) == x)
            borrarDescendencia(n, A);
        else 
        {
            Agen<int>::nodo hijo = A.hijoIzqdo(n);
            while(hijo != Agen<int>::NODO_NULO)
            {
                podaRec(hijo, A, x);
                hijo = A.hermDrcho(hijo);
            }
        }
    }
}

void poda(Agen<int>& A, int x)
{
    return podaRec(A.raiz(), A, x);
}
