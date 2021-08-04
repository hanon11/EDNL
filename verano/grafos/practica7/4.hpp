#include <iostream>
#include "../../../grafos/alg_grafoPMC.hpp"

typedef GrafoP<unsigned>::vertice vertice;

struct Parte
{
    unsigned carga;
    GrafoP<unsigned>::vertice ciudad;
};

template <typename tCoste>
void cementosZuelandia(const GrafoP<tCoste>& G, vector<Parte> partes, GrafoP<unsigned>::vertice capital)
{
    vector<GrafoP<unsigned>::vertice> vVer(G.numVert());
    vector<tCoste> D(G.numVert());
    vector<tCoste> DI(G.numVert());
    D = Dijkstra(G, capital, vVer);
    DI = DijkstraInv(G, capital, vVer);
    unsigned total = 0;
    for(int i = 0; i < G.numVert(); ++i)
    {
        for(int j = 0; j < partes.size(); ++j)
        {
            if(i != capital && partes[j].ciudad == i && partes[j].carga > 0) 
                total += partes[j].carga*(D[i]+DI[i]);
        }
    }
    std::cout << "Parte total: " << total << std::endl;
}