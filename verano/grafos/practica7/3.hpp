#include <iostream>
#include "../../../grafos/alg_grafoPMC.hpp"

template <typename tCoste>
void distribucion(GrafoP<tCoste>& G, GrafoP<double>::vertice fabrica, 
            vector<unsigned> capacidad,  vector<double> subvencion, unsigned producto)
{
    vector<typename GrafoP<tCoste>::vertice> vVer(G.numVert());
    vector<tCoste> vCoste(G.numVert());
    vCoste = Dijkstra(G, fabrica, vVer);
    for(int i = 0; i < vCoste.size(); i++)
    {
        std::cout << vCoste[i] << " ";
    }
    std::cout << std::endl;
    for(int i = 0; i < vCoste.size(); ++i)
    {
        if(subvencion[i] > 0 && i != fabrica)
            vCoste[i] *= 1 - subvencion[i]/100;
    }
    for(int i = 0; i < vCoste.size(); i++)
    {
        std::cout << vCoste[i] << " ";
    }
    std::cout << std::endl;
    typename GrafoP<tCoste>::vertice ciudad = fabrica;
    vector<unsigned> reparto(G.numVert());
    while(producto > 0) //mientras quede producto por repartir
    {
        tCoste min = GrafoP<tCoste>::INFINITO;
        //escoger mejor ciudad
        for(int i = 0; i < vCoste.size(); ++i)
        {
            if(i != fabrica && vCoste[i] < min && capacidad[i] > 0)
            {
                min = vCoste[i];
                ciudad = i;
            }
        }
        //si entra todo el producto
        if(capacidad[ciudad] > producto)
        {
            capacidad[ciudad] -= producto;
            reparto[ciudad] = producto;
            producto = 0;
        }
        else //si sigue quedando producto a repartir
        {
            producto -= capacidad[ciudad];
            reparto[ciudad] = capacidad[ciudad];
            capacidad[ciudad] = 0;
        }
    }
    for(int i = 0; i < reparto.size(); i++)
    {
        std::cout << reparto[i] << " ";
    }
    std::cout << std::endl;
}