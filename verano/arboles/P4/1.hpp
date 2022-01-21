#include <iostream>
#include "../../../arbolesBinariosBusqueda/Abb.hpp"
#include <vector>

template <typename T>
void eliminar(Abb<T>& A, T x)
{
    A.buscar(x).~Abb();
}

template <typename T>
void rellenar(std::vector<T>& v, const Abb<T>& A)
{
    if(!A.vacio())
    {
        v.push_back(A.elemento());
        rellenar(v, A.izqdo());
        rellenar(v, A.drcho());
    }
}

template <typename T>
Abb<T> equilibrio(const Abb<T>& A)
{
    Abb<T> result;
    std::vector<T> v;
    rellenar(v, A);
    sort(v.begin(), v.end());
    equilibrioRec(v, result, 0, v.size());
    return result;
}

template <typename T>
void equilibrioRec(std::vector<T> v, Abb<T>& A, unsigned inicio, unsigned fin)
{
    if(fin != inicio)
    {
        unsigned centro = (fin - inicio) / 2 + inicio;
        A.insertar(v[centro]);
        equilibrioRec(v, A, inicio, centro);
        equilibrioRec(v, A, centro+1, fin);
    }
}

template <typename T>
Abb<T> union_(const Abb<T>& A, const Abb<T>& B)
{
    Abb<T> AUB = A;
    unionRec(B, AUB);
    AUB = equilibrio(AUB);
    return AUB;
}

template <typename T>
void unionRec(const Abb<T>& B, Abb<T>& AUB)
{
    if(!B.vacio())
    {
        if(AUB.buscar(B.elemento()).vacio())
        {
            AUB.insertar(B.elemento());
            unionRec(B.izqdo(), AUB);
            unionRec(B.drcho(), AUB);
        } 
        else
        {
            unionRec(B.izqdo(), AUB);
            unionRec(B.drcho(), AUB);
        }
    }
}


template <typename T>
Abb<T> intersec(const Abb<T>& A, const Abb<T>& B)
{
    Abb<T> AnB;
    intersecRec(A, B, AnB);
    AnB = equilibrio(AnB);
    return AnB;
}

template <typename T>
void intersecRec(const Abb<T>& A, const Abb<T>& B, Abb<T>& AnB)
{
    if(!B.vacio() && !A.vacio())
    {
        if(!A.buscar(B.elemento()).vacio())
        {
            AnB.insertar(B.elemento());
            intersecRec(A, B.izqdo(), AnB);
            intersecRec(A, B.drcho(), AnB);
        }
        else
        {
            intersecRec(A, B.izqdo(), AnB);
            intersecRec(A, B.drcho(), AnB);
        }
    }
}

template <typename T>
Abb<T> diferencia(const Abb<T>& A, const Abb<T>& B)
{
    Abb<T> AnB, AUB, A_B;
    AUB = union_(A, B);
    AnB = intersec(A, B);
    diferenciaRec(AUB, AnB, A_B);
    A_B = equilibrio(A_B);
    return A_B;
}

template <typename T>
void diferenciaRec(const Abb<T>& AUB, const Abb<T>& AnB, Abb<T>& A_B)
{
    if(!AUB.vacio())
    {
        if(AnB.buscar(AUB.elemento()).vacio())
        {
            A_B.insertar(AUB.elemento());
            diferenciaRec(AUB.izqdo(), AnB, A_B);
            diferenciaRec(AUB.drcho(), AnB, A_B);
        }
        else
        {
            diferenciaRec(AUB.izqdo(), AnB, A_B);
            diferenciaRec(AUB.drcho(), AnB, A_B);
        }
    }
}