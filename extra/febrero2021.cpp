#include <iostream>
#include "../arbolesBinarios/aBinEnlazada.hpp"
#include "../arbolesBinarios/aBinE-S.hpp"

template <typename T>
bool ascendencia(typename Abin<T>::nodo n, const Abin<T>& A, T elemento)
{

    if(A.padre(n) == Abin<T>::NODO_NULO)
        return false;
    else
    {
        if(A.padre(n) == A.raiz() && A.elemento(A.padre(n)) <= elemento)
            return true;
        else if(A.elemento(A.padre(n)) <= elemento)
            return ascendencia(A.padre(n), A, elemento);
        else 
            return false;
    }
}

template <typename T>
bool descendencia(typename Abin<T>::nodo n, const Abin<T>& A, T elemento)
{
    if(A.hijoDrcho(n) != Abin<T>::NODO_NULO && A.elemento(A.hijoDrcho(n)) >= elemento && 
            A.hijoIzqdo(n) != Abin<T>::NODO_NULO && A.elemento(A.hijoIzqdo(n)) >= elemento)
        return descendencia(A.hijoDrcho(n), A, elemento) && descendencia(A.hijoIzqdo(n), A, elemento);
    if(A.hijoDrcho(n) != Abin<T>::NODO_NULO && A.elemento(A.hijoDrcho(n)) >= elemento && 
            A.hijoIzqdo(n) == Abin<T>::NODO_NULO)
        return descendencia(A.hijoDrcho(n), A, elemento);
    if(A.hijoIzqdo(n) != Abin<T>::NODO_NULO && A.elemento(A.hijoIzqdo(n)) >= elemento && 
            A.hijoDrcho(n) == Abin<T>::NODO_NULO)
        return descendencia(A.hijoIzqdo(n), A, elemento);
    if(A.hijoDrcho(n) == Abin<T>::NODO_NULO && A.hijoIzqdo(n) == Abin<T>::NODO_NULO)
        return true;

    return false;
}

template <typename T>
void poda(Abin<T>& A)
{
    return podaRec(A.raiz(), A);
}

template <typename T>
void podaRec(typename Abin<T>::nodo n, Abin<T>& A)
{
    if(n != Abin<T>::NODO_NULO)
    {
        if(descendencia(n, A, A.elemento(n)) && ascendencia(n, A, A.elemento(n)))
            eliminar(n, A);
        else
        {
            podaRec(A.hijoDrcho(n), A);
            podaRec(A.hijoIzqdo(n), A);
        }
    }
}

template <typename T>
void eliminar(typename Abin<T>::nodo n, Abin<T>& A)
{
    if(n != Abin<T>::NODO_NULO && A.hijoDrcho(n) != Abin<T>::NODO_NULO)
    {
        eliminar(A.hijoDrcho(n), A);
        A.eliminarHijoDrcho(n);
    }
    if(n != Abin<T>::NODO_NULO && A.hijoIzqdo(n) != Abin<T>::NODO_NULO)
    {
        eliminar(A.hijoIzqdo(n), A);
        A.eliminarHijoIzqdo(n);
    }
}

int main()
{
    Abin<int> A;
    std::ifstream fs("abin2.dat");
    rellenarAbin(fs, A);
    imprimirAbin(A);
    //imprimirAbin(A);
    poda(A);
    std::cout << std::endl;
    imprimirAbin(A);
}