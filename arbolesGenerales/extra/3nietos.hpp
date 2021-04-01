#include "../aGenEnlazada.hpp"
template <typename T>
unsigned nietos(const Agen<T>& A)
{
    return nietosRec(A.raiz(), A);
}

template <typename T>
unsigned nietosRec(typename Agen<T>::nodo n, const Agen<T>& A)
{
    unsigned numNietos = 0;
    typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
    bool encontrado = false;
    if(n != Agen<T>::NODO_NULO && hijo != Agen<T>::NODO_NULO)
    {
        while(hijo != Agen<T>::NODO_NULO)
        {
            if(contarHijos(hijo, A) == 3 && !encontrado)
            {
                numNietos++;
                encontrado = true;
            }
            numNietos += nietosRec(hijo, A);
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