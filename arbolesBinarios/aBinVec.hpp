#ifndef ABIN_VEC_HPP
#define ABIN_VEC_HPP
#include <cassert>
#include <cstdint>

template<typename T> 
class AbinVec
{
public:
    typedef std::size_t nodo;
    static const nodo NODO_NULO;
    explicit AbinVec(std::size_t maxNodos);
    void insertarRaiz(const T& e);
    void insertarHijoIzqdo(nodo n, const T& e);
    void insertarHijoDrcho(nodo n, const T& e);
    void eliminarHijoIzqdo(nodo n);
    void eliminarHijoDrcho(nodo n);
    void eliminarRaiz();
    bool arbolVacio() const;
    const T& elemento (nodo n) const; //solo lectura
    T& elemento(nodo n);
    nodo raiz() const;
    nodo padre(nodo n) const;
    nodo hijoIzqdo(nodo n) const;
    nodo hijoDrcho(nodo n) const;
    AbinVec(const AbinVec<T>& A);
    AbinVec<T>& operator=(const AbinVec<T>& A);
    ~AbinVec();
private:
    struct celda{
        T elto;
        nodo padre, hizq, hder;
    };
    celda *nodos; //vector de nodos
    std::size_t maxNodos; //tam. del vector
    std::size_t numNodos; //numero de nodos del arbol

};


//definicion de nodo nulo
template <typename T>
const typename AbinVec<T>::nodo AbinVec<T>::NODO_NULO(SIZE_MAX);

template <typename T>
inline AbinVec<T>::AbinVec(std::size_t maxNodos) :
    nodos(new celda[maxNodos]),
    maxNodos(maxNodos),
    numNodos(0)
{}


template <typename T>
inline void AbinVec<T>::insertarRaiz(const T& e)
{
    assert(numNodos == 0);

    numNodos = 1;
    nodos[0].elto = e;
    nodos[0].padre = NODO_NULO;
    nodos[0].hizq = NODO_NULO;
    nodos[0].hder = NODO_NULO;
}

template <typename T>
inline void AbinVec<T>::insertarHijoIzqdo(nodo n, const T& e)
{
    assert(n >= 0 && n < numNodos); //nodo valido
    assert(nodos[n].hizq == NODO_NULO); //n no tiene hijo izq
    assert(numNodos < maxNodos); // arbol no lleno

    //add new nodo
    nodos[n].hizq = numNodos;
    nodos[numNodos].elto = e;
    nodos[numNodos].padre = n;
    nodos[numNodos].hizq = NODO_NULO;
    nodos[numNodos].hder = NODO_NULO;
    ++numNodos;
}


template <typename T>
inline void AbinVec<T>::insertarHijoDrcho(nodo n, const T& e)
{
    assert(n >= 0 && n < numNodos); //nodo valido
    assert(nodos[n].hder == NODO_NULO);//n no tiene hijo drch
    assert(numNodos < maxNodos); //arbol no lleno
    
    //add new nodo
    nodos[n].hder = numNodos;
    nodos[numNodos].elto = e;
    nodos[numNodos].padre = n;
    nodos[numNodos].hizq = NODO_NULO;
    nodos[numNodos].hder = NODO_NULO;
    ++numNodos;
 }

template <typename T>
void AbinVec<T>::eliminarHijoIzqdo(nodo n)
{
    nodo hizqdo;
    assert(n >= 0 && n < numNodos);//nodo valido
    hizqdo = nodos[n].hizq;
    assert(hizqdo != NODO_NULO);
    assert(nodos[hizqdo].hizq == NODO_NULO && nodos[hizqdo].hder == NODO_NULO);
    //hijo izq de n es hoja

    if(hizqdo!= numNodos-1)
    {// Mover el último nodo a la posición del hijo izqdo.
        nodos[hizqdo] = nodos[numNodos-1];// Actualizar la posición del hijo (izquierdo o derecho) en el padre del nodo movido.
        if(nodos[nodos[hizqdo].padre].hizq == numNodos-1)
            nodos[nodos[hizqdo].padre].hizq = hizqdo;
        else
            nodos[nodos[hizqdo].padre].hder= hizqdo;
        // Si el nodo movido tiene hijos, actualizar la posición del padre.
        if(nodos[hizqdo].hizq != NODO_NULO)
            nodos[nodos[hizqdo].hizq].padre = hizqdo;
        if(nodos[hizqdo].hder!= NODO_NULO)
            nodos[nodos[hizqdo].hder].padre = hizqdo;
    }
    
    nodos[n].hizq= NODO_NULO;
    --numNodos;
}
 
 





#endif
