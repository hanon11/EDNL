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


//EJERCICIO 3
template <typename T>
void union_(const Abb<T>& A, const Abb<T>& B, Abb<T>& AUB)
{
    Abb<T> final;
    union1(A,B,AUB);
    union2(A,B,AUB);
    equilibrio(AUB, final);
    AUB = final;
    
}

template <typename T>
void union1(const Abb<T>& A, const Abb<T>& B, Abb<T>& AUB)
{
    if(!A.vacio())
    {
        AUB.insertar(A.elemento());
        union1(A.izqdo(), B, AUB);
        union1(A.drcho(), B, AUB);
    }
}

template <typename T>
void union2(const Abb<T>& A, const Abb<T>& B, Abb<T>& AUB)
{
    if(!B.vacio())
    {
        if(A.buscar(B.elemento()).vacio())
        {
            AUB.insertar(B.elemento());
            union_(A, B.izqdo(), AUB);
            union_(A, B.drcho(), AUB);
        }
        else
        {
            union_(A, B.izqdo(), AUB);
            union_(A, B.drcho(), AUB);
        }
    }
}


//EJERCICIO 4
template <typename T>
void intersec(const Abb<T>& A, const Abb<T>& B, Abb<T>& ANB)
{
    if(!A.vacio() && !B.vacio())
    {
        if(!A.buscar(B.elemento()).vacio())
        {
            ANB.insertar(B.elemento());
            intersec(A, B.izqdo(), ANB);
            intersec(A, B.drcho(), ANB);
        }
        else
        {
            intersec(A, B.izqdo(), ANB);
            intersec(A, B.drcho(), ANB);
        }
    }
    
}


//EJERCICIO 5
template <typename T>
void diferencia(const Abb<T>& A, const Abb<T>& B, Abb<T>& ANB)
{
    Abb<T> final;
    diferenciaRec1(A, B, ANB);
    diferenciaRec2(A, B, ANB);
    equilibrio(ANB, final);
    ANB = final;
}

template <typename T>
void diferenciaRec1(const Abb<T>& A, const Abb<T>& B, Abb<T>& ANB)
{
    if(!A.vacio() && !B.vacio())
    {
        if(A.buscar(B.elemento()).vacio())
        {
            ANB.insertar(B.elemento());
            diferenciaRec1(A, B.izqdo(), ANB);
            diferenciaRec1(A, B.drcho(), ANB);
        }
        else
        {
            diferenciaRec1(A, B.izqdo(), ANB);
            diferenciaRec1(A, B.drcho(), ANB);
        }
    }
}

template <typename T>
void diferenciaRec2(const Abb<T>& A, const Abb<T>& B, Abb<T>& ANB)
{
    if(!A.vacio())
    {
        if(B.buscar(A.elemento()).vacio())
        {
            ANB.insertar(A.elemento());
            diferenciaRec2(A.izqdo(), B, ANB);
            diferenciaRec2(A.drcho(), B, ANB);
        }
        else
        {
            diferenciaRec2(A.izqdo(), B, ANB);
            diferenciaRec2(A.drcho(), B, ANB);
        }
    }
}


//reusando codigo
template <typename T>
void dif(const Abb<T>& A, const Abb<T>& B, Abb<T>& ANB)
{
    Abb<T> un, inter, final;
    union_(A, B, un);
    intersec(A, B, inter);
    difRec(un, inter, ANB);
    equilibrio(ANB, final);
    ANB = final;
}

template <typename T>
void difRec(const Abb<T>& un, const Abb<T>& inter, Abb<T>& ANB)
{
    if(!un.vacio())
    {
        if(inter.buscar(un.elemento()).vacio())
        {
            ANB.insertar(un.elemento());
            difRec(un.izqdo(), inter, ANB);
            difRec(un.drcho(), inter, ANB);
        }
        else
        {
            difRec(un.izqdo(), inter, ANB);
            difRec(un.drcho(), inter, ANB);
        }
    }
}
