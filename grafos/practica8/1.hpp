#include <iostream>
#include "../alg_grafoPMC.hpp"
#include "../alg_grafoMA.hpp"
#include "../grafoMA.hpp"
#include "../particion.hpp"
#include <cmath>
#include <algorithm>
template <typename tCoste>
struct isla
{
    tCoste x, y;
    isla(tCoste x1, tCoste y1) : x(x1), y(y1){};
};


void tombuctu(Grafo archipielago, vector<isla<double> > islas)
{
    //se puede hacer tambien con warshall
    unsigned N = archipielago.numVert();
    GrafoP<double> G(N);
    Particion p(N);
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            if(archipielago[i][j])
            {
                G[i][j] = std::sqrt(std::pow(islas[i].x - islas[j].x, 2) + 
                                    std::pow(islas[i].y - islas[j].y, 2));
                if(p.encontrar(i) != p.encontrar(j))
                    p.unir(p.encontrar(i), p.encontrar(j));
            }
        }
    } 
    matriz<typename Grafo::vertice> vVer;
    matriz<double> mCostes = Floyd(G, vVer);

    std::cout << mCostes << std::endl;
}