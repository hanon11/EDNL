#include "Abb.hpp"
#include <vector>
#include <iostream>
#include "aBinE-S.hpp"

template <typename T>
void inorden(const Abb<T>& A, std::vector<T>& v)
{
    if(!A.izqdo().vacio())
        inorden(A.izqdo(), v);
    v.push_back(A.elemento());
    if(!A.drcho().vacio())
        inorden(A.drcho(), v);
}

template <typename T>
Abb<T> equilibrar(Abb<T>& A)
{
    std::vector<T> v;
    inorden(A, v);
    Abb<T> eq;
    equilibrarRec(v, eq, 0, v.size());
    return eq;
}

template <typename T>
void equilibrarRec(std::vector<T> v, Abb<T>& eq, int inicio, int fin)
{
    if(fin != inicio)
    {
        int pos = (fin - inicio) / 2 + inicio;
        eq.insertar(v[pos]);
        equilibrarRec(v, eq, inicio, pos);
        equilibrarRec(v, eq, pos+1, fin);
    }
}

template <typename T>
void union2(const Abb<T>& A, const Abb<T>& B, Abb<T>& AUB)
{
    if(!B.vacio())
    {
        if(A.buscar(B.elemento()).vacio())
            AUB.insertar(B.elemento());
        union2(A, B.izqdo(), AUB);
        union2(A, B.drcho(), AUB);
    }
}

template <typename T>
void union_(const Abb<T>& A, const Abb<T>& B, Abb<T>& AUB)
{
    AUB = A;
    union2(A, B, AUB);
    AUB = equilibrar(AUB);
}

template <typename T>
void intersec2(const Abb<T>& A, const Abb<T>& B, Abb<T>& AnB)
{
    if(!B.vacio())
    {
        if(!A.buscar(B.elemento()).vacio())
            AnB.insertar(B.elemento());
        intersec2(A, B.izqdo(), AnB);
        intersec2(A, B.drcho(), AnB);
    }
}

template <typename T>
void intersec(const Abb<T>& A, const Abb<T>& B, Abb<T>& AnB)
{
    intersec2(A, B, AnB);
    AnB = equilibrar(AnB);
}

int main()
{
    Abb<int> A;
    Abb<int> B;
    A.insertar(1);
    A.insertar(2);
    A.insertar(3);
    A.insertar(4);

    B.insertar(4);
    B.insertar(6);
    B.insertar(7);
    B.insertar(8);
    Abb<int> AnB;
    intersec(A, B, AnB);
    imprimirAbb(AnB);
}