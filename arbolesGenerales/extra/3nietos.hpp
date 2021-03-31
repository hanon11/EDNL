#include "../aGenEnlazada.hpp"
template <typename T>
unsigned nietos(typename Agen<T>::nodo n, const Agen<T>& A)
{
    unsigned numNietos = 0;
    typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
    if(n != Agen<T>::NODO_NULO && hijo != Agen<T>::NODO_NULO)
    {   
        if(contarHijos(hijo, A) == 3)
            numNietos++;
        while(hijo != Agen<T>::NODO_NULO)
        {
            nietos(hijo, A);
            if(contarHijos(hijo, A) == 3)
                numNietos++;
            hijo = A.hermDrcho(hijo);
        }    
    }
    return numNietos;
}

template <typename T>
unsigned contarHijos(typename Agen<T>::nodo n, const Agen<T>& A)
{
    typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
    unsigned numHijos = 0;

    while(hijo != Agen<T>::NODO_NULO)
    {
        numHijos++;
        hijo = A.hermDrcho(hijo);
    }
    return numHijos;
}