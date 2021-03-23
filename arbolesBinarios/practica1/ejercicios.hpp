#include "../aBinE-S.hpp"
#include "../aBinEnlazada.hpp"

//EJERCICIO1
template<typename T>
unsigned numNodos(const Abin<T>& A){

    return numNodos_Rec(A.raiz(), A);
}

template <typename T>
unsigned numNodos_Rec(typename Abin<T>::nodo n, const Abin<T>& A)
{

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
int desequilibrio_rec(const Abin<T>& A, typename Abin<T>::nodo n)
{
    if (n == Abin<T>::NODO_NULO)
        return 0;
    else
        return std::max(std::abs(A.altura(A.hijoDrcho(A)) - A.altura(A.hijoIzqdo(A))), std::max(desequilibrio_rec(A, A.hijoDrcho(A)),desequilibrio_rec(A,A.hijoIzqdo(A))));
}

//EJERCICIO 7
template <typename T>
bool pseudocompleto(Abin<T>& A)
{
    return pseudocompletoRec(A.raiz(), A);
}

template <typename T>
bool pseudocompletoRec(typename Abin<T>::nodo n, Abin<T>& A)
{
    if (A.altura(n) == -1) //es nodo nulo
            return true;
    else if (A.altura(n) == 1)//si es hoja
            return (A.hijoDrcho(n) != Abin<T>::NODO_NULO && A.hijoIzqdo(n) != Abin<T>::NODO_NULO);
    else
    {
        if(A.altura(A.hijoDrcho(n)) == A.altura(A.hijoIzqdo(n)))
        {
            return (pseudocompletoRec(A.hijoIzqdo(n), A) && pseudocompletoRec(A.hijoDrcho(n), A));
        }
        else
        {
            if(A.altura(A.hijoDrcho(n)) > A.altura(A.hijoIzqdo(n)))
                return pseudocompletoRec(A.hijoDrcho(n), A);
            else
                return pseudocompletoRec(A.hijoIzqdo(n), A);
        }
    }
}
