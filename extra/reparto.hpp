/*Un repartidor de una empresa de distribución de bebidas tiene que visitar a todos sus
clientes cada día. Pero, al comenzar su jornada de trabajo, no conoce qué cantidad de bebidas
tiene que servir a cada cliente, por lo que no puede planificar una ruta óptima para visitarlos a
todos. Por tanto, nuestro repartidor decide llevar a cabo la siguiente estrategia: 
 El camión parte del almacén con la máxima carga permitida rumbo a su cliente más
próximo.
 El repartidor descarga las cajas de bebidas que le pide el cliente. Si no tiene suficientes
cajas en el camión, le entrega todas las que tiene. Este cliente terminará de ser servido en
algún otro momento a lo largo del día, cuando la estrategia de reparto vuelva a llevar al
repartidor hasta él.
 Después de servir a un cliente: 
    o Si quedan bebidas en el camión, el repartidor consulta su sistema de navegación
    basado en GPS para conocer la ruta que le lleva hasta su cliente más próximo
    pendiente de ser servido.
    o Si no quedan bebidas en el camión, vuelve al almacén por el camino más corto y
    otra vez carga el camión completamente.

 Después de cargar el camión, el repartidor consulta su sistema de navegación y se va por
el camino más corto a visitar al cliente pendiente de ser servido más próximo.
Implementa un subprograma que calcule y devuelva la distancia total recorrida en un
día por nuestro repartidor, a partir de lo siguiente:
1. Grafo representado mediante matriz de costes con las distancias de los caminos directos
entre los clientes y entre ellos y la central.
2. Capacidad máxima del camión (cantidad de cajas de bebidas).
3. Asumiremos que existe una función int Pedido() que devuelve el número de cajas que
quedan por servir al cliente en el que se encuentra el repartidor.*/

#include <iostream>
#include "../grafos/alg_grafoPMC.hpp"

bool r(vector<int> v)
{
    for(int i = 0; i < v.size(); ++i)
        if(v[i] == 0)
            return false;
    return true;
}

template <typename tCoste>
tCoste reparto(const GrafoP<tCoste>& G, typename GrafoP<tCoste>::vertice central, unsigned capacidad,
    vector<unsigned> pendiente)
{
    unsigned cont = 0;
    vector<typename GrafoP<tCoste>::vertice> vVer(G.numVert());
    unsigned cliente = central;
    tCoste min = GrafoP<tCoste>::INFINITO;
    tCoste distancia = 0;
    unsigned capacidadAux = capacidad;
    vector<int> servidos(G.numVert(), 1); // 1 si 0 no
    for(int i = 0; i < servidos.size(); ++i)
        if(pendiente[i] > 0)
            servidos[i] = 0;
    while(true)
    {
        vector<tCoste> vCostes = Dijkstra(G, cliente, vVer);
        min = GrafoP<tCoste>::INFINITO;
        for(int i = 0; i < G.numVert(); ++i)
        {
            if(i != central && i != cliente)
            {
                if(vCostes[i] < min && pendiente[i] > 0)
                {
                    min = vCostes[i];
                    cliente = i;
                }
            }
        }
        if(r(servidos))
            break;
        else
        {
            distancia += vCostes[cliente];
            if(pendiente[cliente] > capacidadAux)
            {
                pendiente[cliente] -= capacidadAux;
                vector<tCoste> vuelta = Dijkstra(G, cliente, vVer);
                distancia += vuelta[central];
                capacidadAux = capacidad; 
                cliente = central;
            }
            else if(pendiente[cliente] == capacidadAux)
            {
                pendiente[cliente] = 0;
                servidos[cliente] = 1;
                vector<tCoste> vuelta = DijkstraInv(G, central, vVer);
                distancia += vuelta[cliente];
                capacidadAux = capacidad; 
                cliente = central;
            }
            else
            {
                capacidadAux -= pendiente[cliente];
                pendiente[cliente] = 0;
                servidos[cliente] = 1;
            }
        }
    }
    return distancia;
}

