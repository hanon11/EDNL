#include "../alg_grafoPMC.hpp"
#include <iostream>
#include <vector>
using std::size_t;

struct casilla
{
    int fila, columna;
    casilla(int x, int y) : fila(x), columna(y){};
};

bool adyacentes(casilla c1, casilla c2)
{
    return ((abs(c1.columna - c2.columna) + abs(c1.fila - c2.fila)) == 1);
}

casilla nodoToCasilla(size_t nodo, size_t n)
{
    casilla aux(0,0);
    aux.fila = nodo/n;
    aux.columna = nodo%n;
    return aux;
}

unsigned casillaToNodo(casilla c1, size_t n)
{
    return (c1.fila * n) + c1.columna;
}

struct pared
{
    size_t origen, destino;
    //pared(int o, int d) : origen(o), destino(d){};
};

vector<casilla> laberinto(size_t n, Lista<pared> paredes, casilla origen, casilla destino)
{
    GrafoP<size_t>::vertice vOrigen = casillaToNodo(origen, n);
    GrafoP<size_t>::vertice vDestino = casillaToNodo(destino, n);
    GrafoP<size_t> G(n*n);
    for(size_t i = 0; i < n*n; i++)
    {
        for(size_t j = 0; j < n*n; j++)
        {
            if(i == j)
                G[i][j] = 0;
            else if(adyacentes(nodoToCasilla(i, n), nodoToCasilla(j, n)))
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
    Lista<pared>::posicion pos = paredes.primera();
    while(pos != paredes.fin())
    {
        G[paredes.elemento(pos).destino][paredes.elemento(pos).origen] = GrafoP<size_t>::INFINITO;
        G[paredes.elemento(pos).origen][paredes.elemento(pos).destino] = GrafoP<size_t>::INFINITO;
        pos = paredes.siguiente(pos);
    }
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
    return rutaCasillas;
}