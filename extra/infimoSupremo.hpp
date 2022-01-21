#include <iostream>
#include "../arbolesBinariosBusqueda/Abb.hpp"
#include <climits>

template <typename tCoste>
void minimo(const Abb<tCoste>& A, tCoste& min)
{
    if(!A.vacio())
    {
        min = A.elemento();
        minimo(A.izqdo(), min);
    }
}

template <typename tCoste>
void maximo(const Abb<tCoste>& A, tCoste& max)
{
    if(!A.vacio())
    {
        max = A.elemento();
        maximo(A.drcho(), max);
    }
}

template <typename tCoste>
void infimo(const Abb<tCoste>& A, tCoste x, tCoste& min)
{
    if(!A.vacio())
    {
        if(A.elemento() > x)
            return infimo(A.izqdo(), x, min);
        if(A.elemento() < x)
        {
            if(A.elemento() > min)
                min = A.elemento();
            return infimo(A.drcho(), x, min);
        }
    }
}

template <typename tCoste>
void supremo(const Abb<tCoste>& A, tCoste x, tCoste& max)
{
    if(!A.vacio())
    {
        if(A.elemento() > x)
        {
            if(A.elemento() < max)
                max = A.elemento();
            return supremo(A.izqdo(), x, max);
        }
        if(A.elemento() < x)
            return supremo(A.drcho(), x, max);
    }
}

template <typename tCoste>
void calcular(const Abb<tCoste>& A, tCoste x)
{
    tCoste min = 0, max = INT_MAX;
    infimo(A, x, min);
    if(min == 0)
    {
        minimo(A, min);
        std::cout << "Minimo: " << min << std::endl;
    }
    else 
        std::cout << "Infimo: " << min << std::endl;
    supremo(A, x, max);
    if(max == INT_MAX)
    {
        maximo(A, max);
        std::cout << "Maximo: " << max << std::endl;
    }
    else
        std::cout << "Supremo: " << max << std::endl;
}