#include "../alg_grafoPMC.hpp"
#include "../alg_grafo_E-S.hpp"
#include <vector>
#include <iostream>
template <typename tCoste>
struct carretera
{
    typename GrafoP<tCoste>::vertice origen, destino;
    carretera(typename GrafoP<tCoste>::vertice o, typename GrafoP<tCoste>::vertice d) : origen(o), destino(d){}
};

template <typename tCoste>
void eliminaCarreteras(GrafoP<tCoste>& G, std::vector<carretera<tCoste> > carreteras)
{
    for(int i = 0; i < carreteras.size(); ++i)
        G[carreteras[i].origen][carreteras[i].destino] = GrafoP<tCoste>::INFINITO;
}

template <typename tCoste>
void eliminaCiudades(GrafoP<tCoste>& G, std::vector<typename GrafoP<tCoste>::vertice> ciudades)
{
    for(int i = 0; i < ciudades.size(); ++i)
    {
        for(int j = 0; j < G.numVert(); ++j)
            G[ciudades[i]][j] = G[j][ciudades[i]] = GrafoP<tCoste>::INFINITO;
    }
}
        

template <typename tCoste>
void viaje(GrafoP<tCoste>& G, std::vector<typename GrafoP<tCoste>::vertice> ciudades, 
        std::vector<carretera<tCoste> > carreteras, typename GrafoP<tCoste>::vertice capital)
{
    vector<tCoste> D(G.numVert());
    vector<tCoste> I(G.numVert());
    vector<typename GrafoP<tCoste>::vertice> vVer(G.numVert());

    D = Dijkstra(G, capital, vVer);
    I = DijkstraInv(G, capital, vVer);
    std::cout << D << std::endl;
    std::cout << I << std::endl;

    for(int i = 0; i < G.numVert(); ++i)
    {
        for(int j = 0; j < G.numVert(); ++j)
            if(i != j)
                G[i][j] = suma(D[j], I[i]);
    }
    std::cout << G;
}

int main()
{
    GrafoP<unsigned> E4("zuelandia.dat");
    vector<GrafoP<unsigned>::vertice> ciudad;
    vector<carretera<unsigned> > carreteras;
    carretera<unsigned> carretera1(0,2), carretera2(1,2);
    ciudad.insert(ciudad.begin(), 2);
    viaje(E4, ciudad, carreteras, 2);
}