#include "../aBinEnlazada.hpp"

using std::size_t;

bool hoja(typename Abin<double>::nodo n, const Abin<double>& A)
{
    return (A.hijoIzqdo(n) == Abin<double>::NODO_NULO && A.hijoDrcho(n) == Abin<double>::NODO_NULO);
}

bool ascendencia(typename Abin<double>::nodo n, const Abin<double>& A)
{
    if(A.padre(n) == Abin<double>::NODO_NULO)
        return true;
    else
    {
        if(A.elemento(A.padre(n)) < A.elemento(n))
            return ascendencia(A.padre(n), A);
        else
            return false;
    }

}

bool descendencia(typename Abin<double>::nodo n, const Abin<double>& A)
{
    if(A.hijoDrcho(n) == Abin<double>::NODO_NULO)
        return true;
    else
    {
        if(A.elemento(A.hijoDrcho(n)) > A.elemento(n))
            return descendencia(A.hijoDrcho(n), A);
        else
            return false;
    }
    
    if(A.hijoIzqdo(n) == Abin<double>::NODO_NULO)
        return true;
    else
    {
        if(A.elemento(A.hijoIzqdo(n)) > A.elemento(n))
            return descendencia(A.hijoIzqdo(n), A);
        else
            return false;
    }

}

size_t prosperosRec(typename Abin<double>::nodo n, const Abin<double>& A)
{
    if(n == Abin<double>::NODO_NULO || hoja(n, A))
        return 0;
    else
    {
        if(n == A.raiz())
            return prosperosRec(A.hijoDrcho(n), A) + prosperosRec(A.hijoIzqdo(n), A);
        else if(ascendencia(n, A) && descendencia(n, A))
            return 1 + prosperosRec(A.hijoDrcho(n), A) + prosperosRec(A.hijoIzqdo(n), A);
        else
            return prosperosRec(A.hijoDrcho(n), A) + prosperosRec(A.hijoIzqdo(n), A);
    }
    
}

size_t prosperos(const Abin<double>& A)
{
    return prosperosRec(A.raiz(), A);
}