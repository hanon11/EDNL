#include <iostream>
#include <cmath>
#include "../alg_grafoMA.hpp"
#include "../alg_grafoPMC.hpp"

struct puente
{
    int fobos, deimos;
    double coste;
};

struct ciudad
{
    double x_, y_;
    ciudad(double x, double y) : x_(x), y_(y){};
};
typedef GrafoP<int>::vertice vertice;



double distancia(ciudad c1, ciudad c2)
{
    return (std::sqrt(static_cast<double>(std::pow(std::abs(c1.x_-c2.x_), 2))+static_cast<double>(std::pow(std::abs(c1.y_-c2.y_), 2))));
}

puente puenteCosteMinimo(vector<ciudad> fobos, vector<ciudad> deimos, vector<vertice> costaFobos,
     vector<vertice> costaDeimos)
{
    puente puenteMin;
    puenteMin.fobos = 0;
    puenteMin.deimos = 0;
    puenteMin.coste = GrafoP<double>::INFINITO;
    for (int i = 0; i < costaFobos.size(); ++i)
        for (int j = 0; j < costaDeimos.size(); ++j)
        {
            double coste = distancia(fobos[costaFobos[i]], deimos[costaDeimos[j]]);
            if (coste < puenteMin.coste)
            {
                puenteMin.coste = coste;
                puenteMin.fobos = costaFobos[i];
                puenteMin.deimos = costaDeimos[i];
            }
        }
    return puenteMin;
}

void grecoland(const vector<ciudad> Fobos, const vector<ciudad> Deimos, const vector<vertice> costerasFobos, 
    const vector<vertice> costerasDeimos, vertice origen, vertice destino)
{
    GrafoP<double> fobos(Fobos.size());
    for(int i = 0; i < Fobos.size(); ++i)
    {
        for(int j = i+1; j <= Fobos.size()-1; ++j)
        {
            fobos[j][i] = fobos[i][j] = distancia(Fobos[i], Fobos[j]);
        }
    }
    GrafoP<double> fobosPostPrim = Prim(fobos);
    GrafoP<double> deimos(Deimos.size());
    for(int i = 0; i < Deimos.size(); ++i)
    {
        for(int j = i+1; j <= Deimos.size()-1; ++j)
        {
            deimos[j][i] = deimos[i][j] = distancia(Deimos[i], Deimos[j]);
        }
    }
    GrafoP<double> deimosPostPrim = Prim(deimos);

    GrafoP<double> archipielago(deimosPostPrim.numVert()+fobosPostPrim.numVert());
    for(int i = 0; i < fobosPostPrim.numVert(); ++i)
    {
        for(int j = i+1; j <= fobosPostPrim.numVert()-1; ++j)
            archipielago[j][i] = archipielago[i][j] = fobosPostPrim[i][j];
    }
    for(int i = 0; i < deimosPostPrim.numVert(); ++i)
    {
        for(int j = i+1; j <= deimosPostPrim.numVert()-1; ++j)
            archipielago[j+fobosPostPrim.numVert()][i+fobosPostPrim.numVert()] = archipielago[i+fobosPostPrim.numVert()][j+fobosPostPrim.numVert()] = fobosPostPrim[i][j];
    }
    puente puente = puenteCosteMinimo(Fobos, Deimos, costerasFobos, costerasDeimos);
    archipielago[puente.fobos][puente.deimos + Fobos.size()] = archipielago[puente.deimos + Fobos.size()][puente.fobos] = puente.coste;

    vector<vertice> vVer;
    vector<double> costes = Dijkstra(archipielago, origen, vVer);
    std::cout << costes[destino];
}
