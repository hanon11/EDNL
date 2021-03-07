#include "../aBinE-S.h"
#include "../aBinEnlazada.hpp"

//EJERCICIO1
template<typename T>
unsigned numNodos(const Abin<T>& A){

    return numNodos_Rec(A.raiz(), A);
}

template <typename T>
unsigned numNodos_Rec(typename Abin<T>::nodo n, const Abin<T>& A){

    if(n == Abin<T>::NODO_NULO){

        return 0;
    }
    else{
        
        return 1 + numNodos_Rec(A.hijoDrcho(n), A) + numNodos_Rec(A.hijoIzqdo(n), A);
    }
}


//EJERCICIO2
template <typename T>
int altura(const Abin<T>& A)
{
    return alturaRec(A.raiz(), A);
}

template <typename T>
int alturaRec(typename Abin<T>::nodo n, Abin<T>& A)
{
    if(n == Abin<T>::NODO_NULO)
        return -1;
    else 
        return 1 + std::max(alturaRec(A.hijoIzqdo(n), A), alturaRec(A.hijoDrcho(n), A));
}


//EJERCICIO3
template <typename T>
int profundidad(typename Abin<T>::nodo n, const Abin<T>& A)
{
    int profundidad = 0;

    while (n != A.raiz())
    {
        profundidad++;
        n = A.padre(n);
    }

    return profundidad;
}
//forma recursiva
template <typename T>
int profundidadRec(typename Abin<T>::nodo n, const Abin<T>& A)
{
    if (n == Abin<T>::NODO_NULO)
        return -1;
    else 
        return 1 + profundidadRec(A.padre(n), A);
}



//EJERCICIO 6
template <typename T>
int desequilibrio(const Abin<T>& A)
{
    if (A.arbolVacioB())
        return 0;
    else
        return desequilibrio_rec(A, A.raizB());
}


template <typename T>
int desequilibrio_rec(const Abin<T> &A, typename Abin<T>::nodo n)
{
    if (nA == Abin<T>::NODO_NULO)
        return 0;
    else
        return std::max(std::abs(A.alturaB(A.hijoDrchoB(A)) - A.alturaB(A.hijoIzqdoB(A))), std::max(desequilibrio_rec(A, A.hijoDrchoB(A)),desequilibrio_rec(A,A.hijoIzqdoB(A))));
}