#include <iostream>
#include "../arbolesBinarios/aBinEnlazada.hpp"


unsigned ancestros1(Abin<int>::nodo n, const Abin<int>& A)
{
    if(A.padre(n) == Abin<int>::NODO_NULO)
        return 0;
    else
    {
        if(A.elemento(A.padre(n)) == 1)
            return 1 + ancestros1(A.padre(n), A);
        else
            return ancestros1(A.padre(n), A);
    }
}

unsigned ancestros0(Abin<int>::nodo n, const Abin<int>& A)
{
    if(A.padre(n) == Abin<int>::NODO_NULO)
        return 0;
    else
    {
        if(A.elemento(A.padre(n)) == 0)
            return 1 + ancestros0(A.padre(n), A);
        else
            return ancestros0(A.padre(n), A);
    }
}

unsigned rebeldesRec(Abin<int>::nodo n, const Abin<int>& A)
{
    if(n == Abin<int>::NODO_NULO)
        return 0;
    else
    {
        if(A.elemento(n) == 1 && ancestros1(n, A) < ancestros0(n, A))
            return 1 + rebeldesRec(A.hijoDrcho(n), A) + rebeldesRec(A.hijoIzqdo(n), A);
        else if(A.elemento(n) == 0 && ancestros1(n, A) > ancestros0(n, A))
            return 1 + rebeldesRec(A.hijoDrcho(n), A) + rebeldesRec(A.hijoIzqdo(n), A);
        else 
            return rebeldesRec(A.hijoDrcho(n), A) + rebeldesRec(A.hijoIzqdo(n), A);
    }   
}

unsigned rebeldes(const Abin<int>& A)
{
    return rebeldesRec(A.raiz(), A);
}