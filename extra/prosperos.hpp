#include <iostream>
#include "../arbolesBinarios/aBinEnlazada.hpp"

bool ancestros(Abin<double>::nodo n, const Abin<double>& A)
{
    if(A.padre(n) == Abin<double>::NODO_NULO)
        return true;
    else 
    {
        if(A.elemento(A.padre(n)) < A.elemento(n))
            return ancestros(A.padre(n), A);
        else
            return false;
    }
}

bool descendientes(Abin<double>::nodo n, const Abin<double>& A)
{
    if(A.hijoDrcho(n) == Abin<double>::NODO_NULO)
        return true;
    else 
    {
        if(A.elemento(A.hijoDrcho(n)) > A.elemento(n))
            return descendientes(A.hijoDrcho(n), A);
        else
            return false;
    }
    if(A.hijoIzqdo(n) == Abin<double>::NODO_NULO)
        return true;
    else 
    {
        if(A.elemento(A.hijoIzqdo(n)) > A.elemento(n))
            return descendientes(A.hijoIzqdo(n), A);
        else
            return false;
    }
}

unsigned prosperosRec(Abin<double>::nodo n, const Abin<double>& A)
{
    if(n == Abin<double>::NODO_NULO)
        return 0;
    else 
    {
        if(ancestros(n, A) && descendientes(n, A))
            return 1 + prosperosRec(A.hijoIzqdo(n), A) + prosperosRec(A.hijoDrcho(n), A);
        else
            return prosperosRec(A.hijoIzqdo(n), A) + prosperosRec(A.hijoDrcho(n), A);
    }
}

unsigned prosperos(const Abin<double>& A)
{
    return prosperosRec(A.raiz(), A);
}
