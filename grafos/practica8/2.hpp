#include <iostream>
#include "../alg_grafoPMC.hpp"
#include "../alg_grafoMA.hpp"
#include "../particion.hpp"
#include <cmath>
#include <algorithm>

struct LineaAerea
{
    LineaAerea(Grafo::vertice o, Grafo::vertice d, Grafo::vertice co, Grafo::vertice cd,double c) : origen(o), destino(d), ciudadO(co), ciudadD(cd), coste(c){};
    Grafo::vertice origen, destino, ciudadO, ciudadD;
    double coste;
};


void tombuctu2(const Grafo& archipielago, vector<isla<double> > islas)
{
    unsigned n = archipielago.numVert(), nIslas;
    Particion p(n);
    nIslas = n;
    typedef typename Grafo::vertice vertice;

    for(vertice i = 0; i < n; ++i)
    {
        for(vertice j = 0; j < n; ++j)
        {
            if(archipielago[i][j] && p.encontrar(i) != p.encontrar(j))
            {
                --nIslas;
                p.unir(p.encontrar(i), p.encontrar(j));
            }
        }
    }
    std::cout << "Numero de islas: " << nIslas << std::endl; 
    std::cout << "Numero de puentes que necesito: " << nIslas-1 << std::endl; 


    vector<LineaAerea> lineas;

    for(int i = 0; i < n-1; ++i)
    {
        for(int j = i+1; j < n; ++j)
        {
            if(p.encontrar(i) != p.encontrar(j))
            {
                double coste = std::sqrt(std::pow(islas[i].x - islas[j].x, 2) + 
                                    std::pow(islas[i].y - islas[j].y, 2));
                lineas.insert(lineas.end(), LineaAerea(p.encontrar(i), p.encontrar(j), i, j, coste)); 
                std::cout << "Isla origen: " << p.encontrar(i) << "\tCiudad origen: " << i << std::endl;
                std::cout << "Isla destino: " << p.encontrar(j) << "\tCiudad destino: " << j << std::endl;
                std::cout << "Coste: " << coste << std::endl;
            }
        }
    }
}