#include <iostream>
#include "../alg_grafoPMC.hpp"


struct casilla
{
    int fila, columna, prof;
    casilla(int x, int y, int z) : fila(x), columna(y), prof(z){};
};

bool adyacentes(casilla c1, casilla c2, int n)
{
    if(c1.prof == c2.prof)
        return ((abs(c1.columna - c2.columna) + abs(c1.fila - c2.fila)) == 1);
    else 
        return c1.columna == c2.columna && c1.fila == c2.fila && std::abs(c1.prof - c2.prof) == 1;


}

casilla nodoToCasilla(size_t nodo, size_t n)
{
    casilla aux(0,0,0);
    aux.prof = nodo/(n*n);
    nodo = nodo - aux.prof*n*n;
    aux.fila = nodo/n;
    aux.columna = nodo%n;
    return aux;
}

unsigned casillaToNodo(casilla c1, size_t n)
{
    return (c1.fila * n) + c1.columna + (c1.prof*n*n);
}



void laberinto3D(unsigned n, vector<typename GrafoP<std::size_t>::vertice> piedras, casilla origen,
                casilla destino)
{
    std::size_t vOrigen = casillaToNodo(origen, n);
    std::size_t vDestino = casillaToNodo(destino, n);
    GrafoP<std::size_t> G(n*n*n);
    for(std::size_t i = 0; i < n*n*n; i++)
    {
        for(std::size_t j = 0; j < n*n*n; j++)
        {
            if(i == j)
                G[i][j] = 0;
            else if(adyacentes(nodoToCasilla(i, n), nodoToCasilla(j, n), n))
            {    
                G[i][j] = 1;
                G[j][i] = 1;
            }
            else
            {
                G[i][j] = GrafoP<size_t>::INFINITO;
                G[j][i] = GrafoP<size_t>::INFINITO;
            }
        }
    }

    for(std::size_t k = 0; k < piedras.size(); k++)
    {
        for(std::size_t j = 0; j < n*n*n; j++)
        {    
            G[piedras[k]][j] = GrafoP<std::size_t>::INFINITO;
            G[j][piedras[k]] = GrafoP<std::size_t>::INFINITO;
        }
    }

    std::cout << G << std::endl;
    vector<size_t> vCostes;
    vector<GrafoP<size_t>::vertice> vVer;
    vCostes = Dijkstra(G, vOrigen, vVer);
    GrafoP<size_t>::tCamino ruta = camino<GrafoP<size_t>::vertice>(vOrigen, vDestino, vVer);
    vector<casilla> rutaCasillas;
    Lista<GrafoP<size_t>::vertice>::posicion pos2 = ruta.primera();
    while(pos2 != ruta.fin())
    {
        rutaCasillas.insert(rutaCasillas.end(), nodoToCasilla(ruta.elemento(pos2), n));
        pos2 = ruta.siguiente(pos2);
        std::cout <<  "nodo: " << pos2->elto << std::endl;
    }
}