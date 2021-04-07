#include <iostream>
#include "../aBinE-S.hpp"
#include "../Abb.hpp"
#include <vector>
#include <algorithm>

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


//EJERCICIO 2
template <typename T>
void equilibrio(const Abb<T>& A, Abb<T>& B)
{
    std::vector<T> vec;
    fill(vec, A);
    sort(vec.begin(), vec.end()); 
    unsigned tam = vec.size();
    equilibrioRec(vec, B, tam, 0);
}


template <typename T>
void fill(std::vector<T>& vec, const Abb<T>& A)
{
    if(!A.vacio())
    {
        vec.push_back(A.elemento());
        fill(vec, A.izqdo());
        fill(vec, A.drcho());
    }
}


template <typename T>
void equilibrioRec(std::vector<T>& vec, Abb<T>& B, unsigned fin, unsigned ini)
{
    if(fin != ini)
    {  
        unsigned pos = ((fin - ini) / 2) + ini;
        B.insertar(vec[pos]);
        equilibrioRec(vec, B, pos, ini);
        equilibrioRec(vec, B, fin, pos + 1);
    }
}
