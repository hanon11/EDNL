/*La capital de Zuelandia está alcanzando niveles de toxicidad muy elevados, por ello se ha
decretado el cierre a la ciudad como paso de tránsito hacia otras ciudades. (Para ir de una
ciudad a otra no se podrá pasar por C.Zuelandia, pero si se podrá ir si es residente de la misma
empleándola como ciudad destino u origen).
Implemente un subprograma que dada la capital y un grafo ponderado con los km de las
carreteras existentes entre las ciudades del país, nos devuelva los caminos resultantes de
nuestra nueva política “Sin pasar por la capital, por favor”.
Nota impotante: Se ha de definir todos los tipos de dato, prototipo de las operaciones
empleadas en los TADs y también los prototipos de los grafos vistos en clase que se empleen.*/
#include <iostream>
#include "../grafos/alg_grafoPMC.hpp"

template <typename tCoste>
void Zuelandia(const GrafoP<tCoste>& pais, typename GrafoP<tCoste>::vertice capital)
{
    //para los residentes
    typedef typename GrafoP<tCoste>::vertice vertice;
    vector<vertice> vVer(pais.numVert());
    vector<tCoste> D = Dijkstra(pais, capital, vVer);
    vector<tCoste> DI = DijkstraInv(pais, capital, vVer);

    //para los no residentes
    GrafoP<tCoste> G = pais;
    for(vertice i = 0; i < pais.numVert(); ++i)
    {
        G[i][capital] = GrafoP<tCoste>::INFINITO;
        G[capital][i] = GrafoP<tCoste>::INFINITO;
    }
    matriz<vertice> mVer(pais.numVert());
    matriz<tCoste> F = Floyd(pais, mVer);


}