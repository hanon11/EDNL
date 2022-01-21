#ifndef ABIN_VEC_HPP
#define ABIN_VEC_HPP
#include <cassert>
#include <cstdint>
#include <cmath>
template<typename T> 
class AbinVec
{
public:
    typedef std::size_t nodo;
    static const nodo NODO_NULO;
    explicit AbinVec(std::size_t alturaMax);
    void insertarRaiz(const T& e);
    void insertarHijoIzqdo(nodo n, const T& e);
    int altura(nodo n) const;
    nodo raiz() const;
    nodo hijoIzqdo(nodo n) const;
    nodo hijoDrcho(nodo n) const;
    nodo padre(nodo n) const;
    void insertarHijoDrcho(nodo n, const T& e);
    /*void eliminarHijoIzqdo(nodo n);
    void eliminarHijoDrcho(nodo n);
    void eliminarRaiz();
    bool arbolVacio() const;
    const T& elemento (nodo n) const; //solo lectura
    T& elemento(nodo n);
    nodo hijoDrcho(nodo n) const;
    AbinVec(const AbinVec<T>& A);
    AbinVec<T>& operator=(const AbinVec<T>& A);
    ~AbinVec();*/
private:
    T* nodos; // vector de nodos
    std::size_t maxNodos; //tam. del vector
    std::size_t numNodos; //numero de nodos del arbol
    std::size_t maxAltura;
};

template <typename T>
const typename AbinVec<T>::nodo AbinVec<T>::NODO_NULO(SIZE_MAX);

template <typename T>
int AbinVec<T>::altura(nodo n) const
{
    if(n == maxNodos/2) // si es raiz
        return maxAltura;
    else
    {
        if(log2(n+1) == static_cast<int>(log2(n+1))) //si el log2 da solucion entera es que puedo calcular la altura directamente
            return log2(n+1);
        else
        {
            if(n+1 > (maxNodos/2)+1)
                n = maxNodos+1 - (n+1);
            std::size_t nivel = 2;
            while(n+1 < (maxNodos+1)/nivel)
            {
                if(log2(n) == static_cast<int>(log2(n))) //si el log2 da solucion entera es que puedo calcular la altura directamente
                    return log2(n);
                n = (maxNodos+1)/nivel - (n+1);
                nivel += 2;   
            }
            return log2(n);
        }
    }
}

template <typename T>
AbinVec<T>::AbinVec(std::size_t alturaMax) :
    nodos(new T[static_cast<int>(std::pow(2, alturaMax+1)-1)]),
    maxNodos(std::pow(2, alturaMax+1)-1),
    numNodos(0),
    maxAltura(alturaMax)
    {
        std::cout << "Altura maxima de " << alturaMax << " Vector de " << maxNodos << std::endl;
    };

template <typename T>
void AbinVec<T>::insertarRaiz(const T& e)
{
    assert(numNodos == 0);
    numNodos = 1;
    nodos[static_cast<int>(maxNodos/2)] = e;
}

template <typename T>
void AbinVec<T>::insertarHijoIzqdo(nodo n, const T& e)
{
    assert(numNodos < maxNodos); // arbol no lleno

    //add new nodo
    nodos[static_cast<int>(n-std::pow(2, (altura(n)-1)))] = e;
    std::cout << "hijo izqdo de " << n << " en posicion " << static_cast<int>(n-std::pow(2, (altura(n)-1))) << std::endl;
    ++numNodos;
}

template <typename T>
void AbinVec<T>::insertarHijoDrcho(nodo n, const T& e)
{
    assert(numNodos < maxNodos); // arbol no lleno

    //add new nodo
    nodos[static_cast<int>(n+std::pow(2, (altura(n)-1)))] = e;
    std::cout << "hijo drcho de " << n << " en posicion " << static_cast<int>(n+std::pow(2, (altura(n)-1))) << std::endl;
    ++numNodos;
}

template <typename T>
typename AbinVec<T>::nodo AbinVec<T>::raiz() const 
{
    return (numNodos > 0) ? (maxNodos/2) : NODO_NULO;
}
template <typename T>
typename AbinVec<T>::nodo AbinVec<T>::hijoIzqdo(nodo n) const
{
    return n-std::pow(2, (altura(n)-1));
}
template <typename T>
typename AbinVec<T>::nodo AbinVec<T>::hijoDrcho(nodo n) const
{
    return n+std::pow(2, (altura(n)-1));
}

template <typename T> 
typename AbinVec<T>::nodo AbinVec<T>::padre(nodo n) const
{	
	if(nodos[n + static_cast<int>(std::pow(2, altura(n)))] == NODO_NULO)
        return n - static_cast<int>(std::pow(2, altura(n)));
    else 
        return n + static_cast<int>(std::pow(2, altura(n)));
}
#endif //ABINVEC_HPP