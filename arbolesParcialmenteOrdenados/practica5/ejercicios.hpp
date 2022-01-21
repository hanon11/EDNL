#include <iostream>
#include "../apo.hpp"
#include "../../arbolesBinarios/aBinEnlazada.hpp"
#include "../../arbolesGenerales/aGenEnlazada.hpp"

bool hoja(typename Abin<int>::nodo n, Abin<int>& A)
{
    return (A.hijoIzqdo(n) == Abin<int>::NODO_NULO && A.hijoDrcho(n) == Abin<int>::NODO_NULO);
}

//ejercicio1
void sumergir(typename Abin<int>::nodo n, Abin<int>& A)
{
    if(!hoja(n, A) && n != Abin<int>::NODO_NULO) 
    {
        int num {A.elemento(n)};
        if(A.hijoIzqdo(n) != Abin<int>::NODO_NULO && A.hijoDrcho(n) == Abin<int>::NODO_NULO) //solo hijoIzq
        {
            A.elemento(n) = A.elemento(A.hijoIzqdo(n));
            A.elemento(A.hijoIzqdo(n)) = num;
            sumergir(A.hijoIzqdo(n), A);
            
        }
        else if(A.hijoIzqdo(n) == Abin<int>::NODO_NULO && A.hijoDrcho(n) != Abin<int>::NODO_NULO) //solo hijoDrch
        {
            A.elemento(n) = A.elemento(A.hijoDrcho(n));
            A.elemento(A.hijoDrcho(n)) = num;
            sumergir(A.hijoDrcho(n), A);
        }
        else  //si tiene dos hijos
        {
            if(A.elemento(A.hijoIzqdo(n)) < A.elemento(A.hijoDrcho(n)))
            {
                A.elemento(n) = A.elemento(A.hijoIzqdo(n));
                A.elemento(A.hijoIzqdo(n)) = num;
                sumergir(A.hijoIzqdo(n), A);
            }
            else
            {
                A.elemento(n) = A.elemento(A.hijoDrcho(n));
                A.elemento(A.hijoDrcho(n)) = num;
                sumergir(A.hijoDrcho(n), A);
            }
        }
    }
    else
    {
        int max(INT_MAX);
        A.elemento(n) = max;
    }
}

void eliminarRec(typename Abin<int>::nodo n, Abin<int>& A, int elem)
{
    if(n != Abin<int>::NODO_NULO)  //mientras no sea nodo nulo sigo buscando
    {
        if(A.elemento(n) == elem) //si es el elemento que estamos buscando
            sumergir(n, A);
        else
        {
            eliminarRec(A.hijoIzqdo(n), A, elem);
            eliminarRec(A.hijoDrcho(n), A, elem);
        }
        
    }
}

void eliminar(Abin<int>& A, int elem)
{
    eliminarRec(A.raiz(), A, elem);
}



//ejercicio 4
template <typename T>
bool ternario(const Agen<T>& A)
{
    return ternarioRec(A.raiz(), A);
}

template <typename T>
bool ternarioRec(typename Agen<T>::nodo n, const Agen<T>& A)
{
    //todos los nodos son hoja o tienen 3 hijos
    if(n == Agen<T>::NODO_NULO)
        return true;
    else
    {
        if(numHijos(n, A) == 0)
            return true;
        else if(numHijos(n, A) != 3)
            return false;
        else 
        {
            typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
            while(hijo != Agen<T>::NODO_NULO)
            {
                return ternarioRec(hijo, A);
                hijo = A.hermDrcho(hijo);
            }
        }
    }
}

template <typename T>
size_t numHijos(typename Agen<T>::nodo n, const Agen<T>& A)
{
    typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
    size_t num = 0;

    while(hijo != Agen<T>::NODO_NULO)
    {
        num++;
        hijo = A.hermDrcho(hijo);
    }

    return num;
}

