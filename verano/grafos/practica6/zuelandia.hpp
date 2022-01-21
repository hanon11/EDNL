#include <iostream>
#include "../../../grafos/alg_grafoPMC.hpp"

struct carretera
{
    GrafoP<unsigned>::vertice origen, destino;
};

void zuelandia(GrafoP<unsigned>& G, vector<GrafoP<unsigned>::vertice> ciudades,
            vector<carretera> carreteras, GrafoP<unsigned>::vertice capital)
{
    //elimina ciudades
    for(GrafoP<unsigned>::vertice i = 0; i < ciudades.size(); i++)
    {
        for(GrafoP<unsigned>::vertice j = 0; j < G.numVert(); j++)
        {
            G[ciudades[i]][j] = GrafoP<unsigned>::INFINITO;
            G[j][ciudades[i]] = GrafoP<unsigned>::INFINITO;
        }
    }

    //elimina carreteras
    for(GrafoP<unsigned>::vertice i = 0; i < carreteras.size(); i++)
    {
        G[carreteras[i].origen][carreteras[i].destino] = GrafoP<unsigned>::INFINITO;
    }
    vector<unsigned> D(G.numVert()), I(G.numVert());
    vector<GrafoP<unsigned>::vertice> vD(G.numVert()), vI(G.numVert());
    D = Dijkstra(G, capital, vD);
    I = DijkstraInv(G, capital, vI);
    std::cout << "Dijkstra" << std::endl << D << std::endl;
    std::cout << "DijkstraInv" << std::endl << I << std::endl;
    for(GrafoP<unsigned>::vertice i = 0; i < G.numVert(); i++)
    {
        for(GrafoP<unsigned>::vertice j = 0; j < G.numVert(); j++)
        {
            if(i != j)
                G[i][j] = suma(D[j], I[i]);
        }
    }
    std::cout << "Zuelandia" << std::endl << G << std::endl;
}