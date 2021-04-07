#include <iostream>
#include "../aBinE-S.hpp"
#include "../Abb.hpp"

//EJERCICIO 1
template <typename T>
void poda(const T& x, const Abb<T>& A)
{
    A.buscar(x).~Abb();
}

//otra forma
template <typename T>
void podaRec(const T& x, const Abb<T>& A)
{
    if(!A.vacio())
    {
        if(A.elemento() < x)
            podaRec(x, A.drcho());
        else 
        {   if (A.elemento() > x)
                podaRec(x, A.izqdo());
            else 
                A.~Abb();
        }
    }

}


