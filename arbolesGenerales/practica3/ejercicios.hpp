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
        unsigned numHijos = numHijos(nA, A);
        typename Agen<T>::nodo hijo = nA.hijoIzqdo();
        unsigned max = 0;
        while(hijo != Agen<T>::NODO_NULO)
        {
            std::max(max, gradoRec(hijo, A));
            hijo = hijo.hijoIzqdo();
        }
        return std::max(max, numHijos);
    }
}


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


//EJERCICIO 2
template <typename T>
int profundidadRec(typename Agen<T>::nodo n, const Agen<T>& A)
{
    if (n == Agen<T>::NODO_NULO)
        return -1;
    else 
        return 1 + profundidadRec(A.padre(n), A);
}