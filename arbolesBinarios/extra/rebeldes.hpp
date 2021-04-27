#include "../aBinEnlazada.hpp"

unsigned ascendencia1(typename Abin<int>::nodo n, const Abin<int>& A)
{
    if(A.padre(n) == Abin<int>::NODO_NULO)
        return 0;
    else
    {
        if(A.elemento(A.padre(n)) == 1)
            return 1 + ascendencia1(A.padre(n), A);
        else
            return ascendencia1(A.padre(n), A);
    }
}


unsigned ascendencia0(typename Abin<int>::nodo n, const Abin<int>& A)
{
    if(A.padre(n) == Abin<int>::NODO_NULO)
        return 0;
    else
    {
        if(A.elemento(A.padre(n)) == 0)
            return 1 + ascendencia0(A.padre(n), A);
        else
            return ascendencia0(A.padre(n), A);
    }
}

bool rebelde(typename Abin<int>::nodo n, const Abin<int>& A)
{
    if(A.elemento(n) == 1 && ascendencia1(n, A) < ascendencia0(n, A) && A.raiz() != n)
        return true;
    else if(A.elemento(n) == 0 && ascendencia1(n, A) > ascendencia0(n, A) && A.raiz() != n)
        return true;
    else 
        return false;
}


unsigned rebeldesRec(typename Abin<int>::nodo n, const Abin<int>& A)
{
    if(n == Abin<int>::NODO_NULO)
        return 0;
    else
    {
        if (rebelde(n, A))
            return 1 + rebeldesRec(A.hijoDrcho(n), A) + rebeldesRec(A.hijoIzqdo(n), A);
        else
            return rebeldesRec(A.hijoDrcho(n), A) + rebeldesRec(A.hijoIzqdo(n), A);
    }
}
unsigned rebeldes(const Abin<int>& A)
{
    return rebeldesRec(A.raiz(), A);
}


