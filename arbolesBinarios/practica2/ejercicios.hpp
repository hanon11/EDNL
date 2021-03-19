#include "../aBinE-S.h"
#include "../aBinEnlazada.hpp"

//EJERCICIO1
template <typename T>
bool similares(const Abin<T>& A, const Abin<T>& B)
{
    return similaresRec(A.raiz(), A, B.raiz(), B);
}

template <typename T>
bool similaresRec(typename Abin<T>::nodo nA, const Abin<T>& A, typename Abin<T>::nodo nB, const Abin<T>& B)
{
    if (Abin<T>::NODO_NULO == nA && Abin<T>::NODO_NULO == nB)
        return true;
    else
    {
        if (Abin<T>::NODO_NULO == nA || Abin<T>::NODO_NULO == nB)
            return false;
        else
        {
            return (similares_rec(A.hijoIzqdoB(nA), A, B.hijoIzqdoB(n2), B) && similares_rec(A.hijoDrchoB(nA), A, B.hijoDrchoB(nB), B));
        }
    }
}

template <typename T>
Abin<T> reflejado(const Abin<T>& A)
{
    Abin<T> B;
    if(!A.arbolVacio())
    {
        B.insertarRaiz(A.raiz());
        reflejadoRec(A.raiz(), A, B.raiz(), B);
    }
    
    return B;
}

template <typename T>
void reflejadoRec(typename Abin<T>::nodo nA, const Abin<T>& A, typename Abin<T>::nodo nB, Abin<T>& B)
{
    if(Abin<T>::NODO_NULO != A.hijoIzqdoB(nA))
    {
        B.insertarHijoDrchoB(nB,A.elemento(A.hijoIzqdoB(nA)));
        reflejo_rec(A.hijoIzqdoB(nA),A,B.hijoDrchoB(nB),B)
    }

    if(Abin<T>::NODO_NULO != A.hijoDrchoB(nA))
    {
        B.insertarHijoIzqdoB(nB,A.elemento(A.hijoDrchoB(nA)));
        reflejo_rec(A.hijoDrchoB(nA),A,B.hijoIzqdoB(nB),B);
    }
}
