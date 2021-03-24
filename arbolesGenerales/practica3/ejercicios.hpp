#include "../aGenEnlazada.hpp"
//EJERCICIO1
template <typename T>
unsigned grado(const Agen<T>& A)
{
    return gradoRec(A.raiz(), A);
}

template <typename T>
unsigned gradoRec(typename Agen<T>::nodo nA, const Agen<T>& A)
{
    if(nA == Agen<T>::NODO_NULO)
        return 0;
    else
    {
        unsigned nHijos = numHijos(nA, A);
        typename Agen<T>::nodo hijo = A.hijoIzqdo(nA);
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
unsigned numHijos(typename Agen<T>::nodo nA, const Agen<T>& A)
{
    int numHijos = 0;
    typename Agen<T>::nodo hijo = A.hijoIzqdo(nA);
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
unsigned gradoRecNuevo(typename Agen<T>::nodo nA, const Agen<T>& A)
{
    if(nA == Agen<T>::NODO_NULO)
        return 0;
    else
    {
        typename Agen<T>::nodo hijo = A.hijoIzqdo(nA);
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

