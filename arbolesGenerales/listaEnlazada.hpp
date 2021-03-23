#ifndef LISTAENLAZ_HPP_
#define LISTAENLAZ_HPP_
#include <cassert>

template <typename T>
class ListaEnla {
    struct nodo; 
public:
    typedef nodo* posicion; // posición de un elemento
    ListaEnla(); // constructor, requiere ctor. T()
    ListaEnla(const ListaEnla<T>& l); // ctor. de copia, requiere ctor. T()
    ListaEnla<T>& operator=(const ListaEnla<T>& l); // asignación de listas
    void insertar(const T& x, posicion p);
    void eliminar(posicion p);
    const T& elemento(posicion p) const; // acceso a elto, lectura
    T& elemento(posicion p); // acceso a elto, lectura/escritura
    posicion buscar(const T& x) const; // T requiere operador ==
    posicion siguiente(posicion p) const;
    posicion anterior(posicion p) const;
    posicion primera() const;
    posicion fin() const; // posición después del último
    ~ListaEnla(); // destructor
private:
    struct nodo {
        T elto;
        nodo* sig;
        nodo(const T& e, nodo* p = 0)
            : elto(e)
            , sig(p)
        {}
    };
    nodo* L; // lista enlazada de nodos
    void copiar(const ListaEnla<T>& l);
};

template <typename T>
void ListaEnla<T>::copiar(const ListaEnla<T>& l){
    L = new nodo(T()); // crear el nodo cabecera nodo* q = L;
    nodo* q = L;
    for (nodo* r = l.L->sig; r; r = r->sig) {
        q->sig = new nodo(r->elto);
        q = q->sig;
    }
}

template <typename T>
inline ListaEnla<T>::ListaEnla() : L(new nodo(T()))
{} 

template <typename T>
inline ListaEnla<T>::ListaEnla(const ListaEnla<T>& l){
    copiar(l);
}

template <typename T>
ListaEnla<T>& ListaEnla<T>::operator=(const ListaEnla<T>& l){
    if (this != &l) { // evitar autoasignación
        this->~ListaEnla(); // vaciar la lista actual
        copiar(l);
    }
    return *this;
}

template <typename T>
inline void ListaEnla<T>::insertar(const T& x, ListaEnla<T>::posicion p){
    p->sig = new nodo(x, p->sig);
}
template <typename T>
inline void ListaEnla<T>::eliminar(ListaEnla<T>::posicion p){
    assert(p->sig); // p no es fin
    nodo* q = p->sig;
    p->sig = q->sig;
    delete q;
}

template <typename T>
inline const T& ListaEnla<T>::elemento(ListaEnla<T>::posicion p) const{
    assert(p->sig); // p no es fin
    return p->sig->elto;
}

template <typename T>
inline T& ListaEnla<T>::elemento(ListaEnla<T>::posicion p){
    assert(p->sig); // p no es fin
    return p->sig->elto;
}

template <typename T>
typename ListaEnla<T>::posicion ListaEnla<T>::buscar(const T& x) const{
    nodo* q = L;
    bool encontrado = false;
    while (q->sig && !encontrado)
        if (q->sig->elto == x)
            encontrado = true;
        else
            q = q->sig;
    return q;
}

template <typename T>
inline typename ListaEnla<T>::posicion ListaEnla<T>::siguiente(ListaEnla<T>::posicion p) const{
    assert(p->sig); // p no es fin
    return p->sig;
}

template <typename T>
typename ListaEnla<T>::posicion ListaEnla<T>::anterior(ListaEnla<T>::posicion p) const {
    nodo* q;
    assert(p != L); // p no es la primera posición
    for (q = L; q->sig != p; q = q->sig);
    return q;
}

template <typename T>
inline typename ListaEnla<T>::posicion ListaEnla<T>::primera() const{
    return L;
}

template <typename T>
typename ListaEnla<T>::posicion ListaEnla<T>::fin() const{
    nodo* p;
    for (p = L; p->sig; p = p->sig);
    return p;
}

// Destructor: destruye el nodo cabecera y vacía la lista
template <typename T>
ListaEnla<T>::~ListaEnla(){
    nodo* q;
    while (L) {
        q = L->sig;
        delete L;
        L = q;
    }
}
#endif // _LISTAENLAZ_HPP_