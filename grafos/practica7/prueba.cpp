#include <iostream>

struct casilla
{
    int fila, columna, prof;
    casilla(int x, int y, int z) : fila(x), columna(y), prof(z){};
};

casilla nodoToCasilla(size_t nodo, size_t n)
{
    casilla aux(0,0,0);
    aux.prof = nodo/(n*n);
    //std::cout << aux.prof << std::endl;
    //std::cout << "Nodo antes: " << nodo << std::endl;
    nodo = nodo - aux.prof*n*n;
    //std::cout << "Nodo despues: " << nodo << std::endl;
    aux.fila = nodo/n;
    aux.columna = nodo%n;
    return aux;
}

unsigned casillaToNodo(casilla c1, size_t n)
{
    return (c1.fila * n) + c1.columna + (c1.prof *n*n);
}


int main()
{
    size_t n1 = 5;
    casilla c1 = nodoToCasilla(n1, 2), c2(2,2, 2);
    //std::cout << c1.fila << " " << c1.columna << " " << c1.prof << std::endl;
    std::cout << casillaToNodo(c2, 3) << std::endl;
}