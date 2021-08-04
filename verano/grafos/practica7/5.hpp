#include <iostream>
#include "../../../grafos/alg_grafoPMC.hpp"
#include <vector>
enum Alergia{C, T, A};
template <typename tCoste>
void viajeroAlergico(const GrafoP<tCoste>& carretera, const GrafoP<tCoste>& tren, const GrafoP<tCoste>& avion,
            double dinero, Alergia alergia, typename GrafoP<tCoste>::vertice salida)
{
    unsigned n = carretera.numVert();
    vector<tCoste> vCostes(carretera.numVert());
    switch (alergia)
    {
        case C: //Carretera
            vCostes = calculoViaje(tren, avion, salida);
            break;
        case T: //tren
            vCostes = calculoViaje(carretera, avion, salida);
            break;
        case A: //avion
            vCostes = calculoViaje(tren, carretera, salida);
            break;
    }
    std::vector<bool> puedeViajar(n, false), visitado(n, false);
    unsigned min = GrafoP<tCoste>::INFINITO;
    typename GrafoP<tCoste>::vertice ciudad = 0;
    bool encontrado = true;
    while(dinero > 0 && encontrado)
    {
        min = GrafoP<tCoste>::INFINITO;
        encontrado = false;
        for(typename GrafoP<tCoste>::vertice i = 0; i < vCostes.size(); ++i)
        {
            if(vCostes[i] < min && i != salida && !visitado[i])
            {
                ciudad = i;
                min = vCostes[i];
                encontrado = true;
            }
        }
        if(encontrado)
        {
            visitado[ciudad] = true;
            puedeViajar[ciudad] = true;
            dinero -= min;
        }
    }
    std::cout << "Ciudades a las que puede viajar: \n";
    for(int i = 0; i < puedeViajar.size(); ++i)
        std::cout << puedeViajar[i] << " ";
    std::cout << std::endl;
}

template <typename tCoste>
vector<tCoste> calculoViaje(const GrafoP<tCoste>& medio1, const GrafoP<tCoste>& medio2, 
            typename GrafoP<tCoste>::vertice salida)
{
    unsigned n = medio1.numVert();
    GrafoP<tCoste> G(n);
    //grafo de costes minimos entre ambos medios de transporte
    for(typename GrafoP<tCoste>::vertice i = 0; i < n; ++i)
    {
        for(typename GrafoP<tCoste>::vertice j = 0; j < n; ++j)
        {
            G[i][j] = std::min(medio1[i][j], medio2[i][j]);
        }
    }
    vector<typename GrafoP<tCoste>::vertice> vVer(n);
    vector<tCoste> vCostes = Dijkstra(G, salida, vVer); //vector de costes minimos desde salida
    return vCostes;
}