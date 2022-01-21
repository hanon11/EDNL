#include <iostream>
#include "../../../grafos/alg_grafoPMC.hpp"
#include <cmath>
struct ciudad
{
    double x_, y_;
    ciudad(double x, double y) : x_(x), y_(y) {};
};

struct puente
{
    double coste;
    GrafoP<double>::vertice fobos, deimos;
};
double distaciaEuclidea(ciudad c1, ciudad c2)
{
    return std::sqrt(std::pow((c2.x_ - c1.x_), 2) + std::pow((c2.y_ - c1.y_), 2));
}

void Grecoland(vector<ciudad> Fobos, vector<ciudad> Deimos, vector<GrafoP<double>::vertice> costerasFobos, 
    vector<GrafoP<double>::vertice> costerasDeimos, GrafoP<double>::vertice origen, 
    GrafoP<double>::vertice destino)
{
    GrafoP<double> F(Fobos.size()), D(Deimos.size());
    for(int i = 0; i < Fobos.size(); ++i)
    {
        for(int j = 0; j < Fobos.size(); ++j)
        {
            if(i == j)
                F[i][j] = 0;
            else
            {
                F[i][j] = distaciaEuclidea(Fobos[i], Fobos[j]);
                F[j][i] = distaciaEuclidea(Fobos[i], Fobos[j]);
            }
        }
    }
    for(int i = 0; i < Deimos.size(); ++i)
    {
        for(int j = 0; j < Deimos.size(); ++j)
        {
            if(i == j)
                D[i][j] = 0;
            else
            {
                D[i][j] = distaciaEuclidea(Deimos[i], Deimos[j]);
                D[j][i] = distaciaEuclidea(Deimos[i], Deimos[j]);
            }
        }
    }
    GrafoP<double> reconstruidoP = Prim(F);
    GrafoP<double> reconstruidoD = Prim(D);
    GrafoP<double> archipielago(reconstruidoP.numVert() + reconstruidoD.numVert());
    for(int i = 0; i < reconstruidoP.numVert(); i++)
    {
        for(int j = 0; j < reconstruidoP.numVert(); j++)
        {
            if(i == j)
                archipielago[i][j] = 0;
            else
                archipielago[i][j] = reconstruidoP[i][j];
        }
    }
    for(int i = 0; i < reconstruidoD.numVert(); i++)
    {
        for(int j = 0; j < reconstruidoD.numVert(); j++)
        {
            if(i == j)
                archipielago[i+reconstruidoP.numVert()][j+reconstruidoP.numVert()] = 0;
            else
                archipielago[i+reconstruidoP.numVert()][j+reconstruidoP.numVert()] = reconstruidoD[i][j];
        }
    }

    puente min, aux;
    min.coste = GrafoP<double>::INFINITO;

    for(int i = 0; i < costerasFobos.size(); ++i)
    {
        for(int j = 0; j < costerasDeimos.size(); ++j)
        {
            aux.coste = distaciaEuclidea(Fobos[costerasFobos[i]], Deimos[costerasDeimos[j]]);
            if(aux.coste < min.coste)
            {
                min.coste = aux.coste;
                min.fobos = costerasFobos[i];
                min.deimos = costerasDeimos[j];
            }
        }
    }
    //colocar mejor puente
    archipielago[min.fobos][min.deimos+F.numVert()] = min.coste;
    archipielago[min.deimos+F.numVert()][min.fobos] = min.coste;
    vector<GrafoP<double>::vertice> vVer(archipielago.numVert());
    vector<double> vCoste = Dijkstra(archipielago, origen, vVer);
    std::cout << vCoste[destino];
}


