#include "../alg_grafoPMC.hpp"
/*La orografía de Zuelandia es un poco especial, las carreteras son muy estrechas
y por tanto solo permiten un sentido de la circulación.
    GRAFO DIRIGIDO
Actualmente Zuelandia es un país en guerra. Y de hecho hay una serie de
ciudades del país que han sido tomadas por los rebeldes, por lo que no pueden
ser usadas para viajar.
    NO PUEDO PASAR POR LOS NODOS DE LAS RESPECTIVAS CIUDADES
Los rebeldes no sólo se han apoderado de ciertas ciudades del país, sino que
también han cortado ciertas carreteras, (por lo que estas carreteras no pueden ser
usadas).
    NO PUEDO USAR LOS CAMINOS
Pero el gobierno no puede permanecer impasible ante la situación y ha exigido
que absolutamente todos los viajes que se hagan por el país pasen por la capital
del mismo, donde se harán los controles de seguridad pertinentes. */




template <typename tCoste>
struct caminos
{
    typename GrafoP<tCoste>::vertice origen, destino;
};

template <typename tCoste>
void eliminaCiudades(GrafoP<tCoste>& G, vector<typename GrafoP<tCoste>::vertice> ciudades)
{
    for(typename GrafoP<tCoste>::vertice v = 0; v < ciudades.size(); v++)
    {
        for(typename GrafoP<tCoste>::vertice i = 0; i < G.numVert(); i++)
        {
            G[i][ciudades[v]] = GrafoP<tCoste>::INFINITO;
            G[ciudades[v]][i] = GrafoP<tCoste>::INFINITO;
        }
    } 
}

template <typename tCoste>
void eliminaCarreteras(GrafoP<tCoste>& G, vector<caminos<tCoste> > carreteras)
{
    for(typename GrafoP<tCoste>::vertice v = 0; v < carreteras.size(); v++)
    {
        G[carreteras[v].origen][carreteras[v].destino] = GrafoP<tCoste>::INFINITO;
        
    } 
}

template <typename tCoste>
void porLaCapital(GrafoP<tCoste>& G, vector<typename GrafoP<tCoste>::vertice> ciudades,
                            vector<caminos<tCoste> > carreteras, typename GrafoP<tCoste>::vertice capital)
{
    //eliminaCarreteras(G, carreteras);
    //eliminaCiudades(G, ciudades);
    vector<tCoste> D(G.numVert()), DInv(G.numVert());
    vector<typename GrafoP<tCoste>::vertice> vD(G.numVert()), vDInv(G.numVert());
    D = Dijkstra(G, capital, vD);
    DInv = DijkstraInv(G, capital, vDInv);
    std::cout << "Dijkstra" << std::endl << D << std::endl;
    std::cout << "DijkstraInv" << std::endl << DInv << std::endl;

    for (typename GrafoP<tCoste>::vertice i = 0; i < G.numVert(); i++)
    {
        for (typename GrafoP<tCoste>::vertice j = 0; j < G.numVert(); j++)
        {
            if (i != j)
                G[i][j] = suma(D[j], DInv[i]);
        }
    }
    std::cout << "Zuelandia" << std::endl << G << std::endl;

}