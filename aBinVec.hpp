#ifndef ABIN_VEC_HPP
#define ABIN_VEC_HPP
#include <cassert>

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


#endif
