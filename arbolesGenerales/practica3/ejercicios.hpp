#include "../aGenEnlazada.hpp"
#include <algorithm>
#include <cmath>
//EJERCICIO1
template <typename T>
unsigned grado(const Agen<T>& A)
{
    return gradoRec(A.raiz(), A);
}

template <typename T>
unsigned gradoRec(typename Agen<T>::nodo n, const Agen<T>& A)
{
    if(n == Agen<T>::NODO_NULO)
        return 0;
    else
    {
        unsigned nHijos = numHijos(n, A);
        typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
        unsigned max = 0;
        while(hijo != Agen<T>::NODO_NULO)
        {
            max = std::max(max, gradoRec(hijo, A));
            hijo = A.hermDrcho(hijo);
        }
        return std::max(max, nHijos);
    }
}

template <typename T>
unsigned numHijos(typename Agen<T>::nodo n, const Agen<T>& A)
{
    int numHijos = 0;
    typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
    while (hijo != Agen<T>::NODO_NULO)
    {
        numHijos++;
        hijo = A.hermDrcho(hijo);
    }

    return numHijos;
}


//OTRA FORMA EJERCICIO 1
template <typename T>
unsigned gradoNuevo(const Agen<T>& A)
{
    return gradoRec(A.raiz(), A);
}

template <typename T>
unsigned gradoRecNuevo(typename Agen<T>::nodo n, const Agen<T>& A)
{
    if(n == Agen<T>::NODO_NULO)
        return 0;
    else
    {
        typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
        unsigned max = 0, cont = 0;
        while(hijo != Agen<T>::NODO_NULO)
        {
            max = std::max(max, gradoRecNuevo(hijo, A));
            hijo = A.hermDrcho(hijo);
            cont++;
        }
        return std::max(max, cont);
    }
}

//EJERCICIO 2
template <typename T>
int profundidadRec(typename Agen<T>::nodo n, const Agen<T>& A)
{
    if (n == Agen<T>::NODO_NULO)
        return -1;
    else 
        return 1 + profundidadRec(A.padre(n), A);
}


//EJERCICIO 3
template <typename T>
unsigned altura(typename Agen<T>:: nodo n, const Agen<T>& A)
{
     if(n == Agen<T>::NODO_NULO)
     {
        return -1;
     }
     else
     {
        typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
        unsigned alturaMax = 0;
        while(hijo != Agen<T>::NODO_NULO)
        {
            alturaMax = std::max(alturaMax, altura(hijo,A));
            hijo = A.hermDrcho(hijo);
        }
        return 1 + alturaMax;
     }
}

template <typename T>
unsigned alturaMin(typename Agen<T>:: nodo n, const Agen<T>& A)
{
    if(n == Agen<T>::NODO_NULO)
    {
        return -1;
    }
    else
    {
        typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
        unsigned alturaMin = altura(n, A);
        while(hijo != Agen<T>::NODO_NULO)
        {
            alturaMin = std::min(alturaMin, altura(hijo,A));
            hijo = A.hermDrcho(hijo);
        }
        return 1 + alturaMin;
    }
}

template <typename T>
unsigned desequilibrio(const Agen<T>& A)
{
    return desequilibrioRec(A.raiz(), A);
}

template <typename T>
unsigned desequilibrioRec(typename Agen<T>::nodo n, const Agen<T>& A)
{
    if(n == Agen<T>::NODO_NULO)
        return 0;
    else
    {
        unsigned desequilibrioMax = 0, alturaMinima = alturaMin(n, A), desNodo = std::fabs(altura(n, A) - alturaMinima );
        typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
        while(hijo != Agen<T>::NODO_NULO)
        {
            desequilibrioMax = std::max(desNodo, desequilibrioRec(hijo, A));
            hijo = A.hermDrcho(hijo);
        }
        return desequilibrioMax;
    }
}

//EJERCICIO 4
void borrarDescendencia(Agen<int>::nodo n, Agen<int>& A)
{
    Agen<int>::nodo hijo = A.hijoIzqdo(n);

    if (n != Agen<int>::NODO_NULO)
    {
        while (hijo != Agen<int>::NODO_NULO && A.hijoIzqdo(hijo) == Agen<int>::NODO_NULO)
        {
            A.eliminarHijoIzqdo(n);
            hijo = A.hijoIzqdo(n);
        }
        if (hijo != Agen<int>::NODO_NULO && A.hijoIzqdo(hijo) != Agen<int>::NODO_NULO)
        {
            borrarDescendencia(hijo, A);
            A.eliminarHijoIzqdo(n);
        }
    }
}

void podaRec(Agen<int>::nodo n, Agen<int>& A, int x)
{
    bool encontrado = false;
    Agen<int>::nodo hijo = A.hijoIzqdo(n);
    if(n != Agen<int>::NODO_NULO && !encontrado)
    {
        if(A.elemento(n) == x)
        {
            encontrado = true;
            borrarDescendencia(n, A);
        }
        else
        {
            hijo = A.hijoIzqdo(n);
            while(hijo != Agen<int>::NODO_NULO)
            {
                podaRec(hijo, A, x);
                hijo = A.hermDrcho(hijo);
            }
        }
    }
}

void poda(int x, Agen<int>& A)
{
    return podaRec(A.raiz(), A, x);
}

