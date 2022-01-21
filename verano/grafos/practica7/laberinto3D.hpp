#include <iostream>
#include "../../../grafos/alg_grafoPMC.hpp"
#include <cmath>

struct pared
{
    size_t origen, destino;
};

struct casilla
{
    int fila, columna, profundidad;
};

casilla nodoToCasilla(size_t nodo, size_t n)
{
    casilla aux;
    aux.profundidad = nodo/(n*n);
    nodo = nodo - aux.profundidad*n*n;
    aux.fila = nodo/n;
    aux.columna = nodo%n;
    return aux;
}

size_t casillaToNodo(casilla c, size_t n)
{
    return c.fila * n + c.columna + c.profundidad * n * n;
}

bool adyacentes(casilla c1, casilla c2)
{
    if(c1.profundidad == c2.profundidad)
        return ((abs(c1.columna - c2.columna) + abs(c1.fila - c2.fila)) == 1);
    else 
        return c1.columna == c2.columna && c1.fila == c2.fila && std::abs(c1.profundidad - c2.profundidad) == 1;
    
}

void laberinto(size_t n, vector<pared> paredes, casilla origen, casilla destino)
{
    GrafoP<size_t> lab(n*n*n);
    GrafoP<size_t>::vertice entrada = casillaToNodo(origen, n);
    GrafoP<size_t>::vertice salida = casillaToNodo(destino, n);
    for(int i = 0; i < n*n*n; ++i)
    {
        for(int j = 0; j < n*n*n; ++j)
        {
            if(i == j)
                lab[i][j] = 0;
            else
            {
                if(adyacentes(nodoToCasilla(i, n), nodoToCasilla(j, n)))
                    lab[i][j] = 1;
                else
                    lab[i][j] = GrafoP<size_t>::INFINITO;
            }
        }
    }
    
    for(int i = 0; i < paredes.size(); ++i)
    {
        lab[paredes[i].destino][paredes[i].origen] = GrafoP<size_t>::INFINITO;
        lab[paredes[i].origen][paredes[i].destino] = GrafoP<size_t>::INFINITO;
    }
    vector<size_t> vCostes;
    vector<GrafoP<size_t>::vertice> vVer;
    vCostes = Dijkstra(lab, entrada, vVer);
    GrafoP<size_t>::tCamino ruta = camino<GrafoP<size_t>::vertice>(entrada, salida, vVer);
    vector<casilla> rutaCasillas;
    Lista<GrafoP<size_t>::vertice>::posicion pos2 = ruta.primera();
    while(pos2 != ruta.fin())
    {
        rutaCasillas.insert(rutaCasillas.end(), nodoToCasilla(ruta.elemento(pos2), n));
        pos2 = ruta.siguiente(pos2);
        std::cout <<  "nodo: " << pos2->elto << std::endl;
    }
}