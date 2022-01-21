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

bool porServir(vector<bool> clientes)
{
    for(int i = 0; i < clientes.size(); ++i)
        if(clientes[i] == false)
            return true;
    return false;
}
int pedido();
unsigned reparto(const GrafoP<unsigned>& G, unsigned capacidad, GrafoP<unsigned>::vertice central)
{
    typedef GrafoP<unsigned>::vertice vertice;
    vertice origen = central;
    unsigned carga = capacidad;
    vector<bool> servidos(G.numVert(), false);
    vector<vertice> vVer(G.numVert());
    vertice proximoCliente;
    unsigned distancia = 0;
    while(porServir(servidos))
    {
        unsigned min = GrafoP<unsigned>::INFINITO;
        vector<unsigned> vCostes = Dijkstra(G, origen, vVer);
        for(int i = 0; i < vCostes.size(); ++i)
        {
            if(vCostes[i] < min && i != origen)
            {
                min = vCostes[i];
                proximoCliente = i;
            }
        }
        if(pedido() > carga)
        {
            distancia += vCostes[proximoCliente];
            vector<unsigned> vuelta = Dijkstra(G, proximoCliente, vVer);
            distancia += vuelta[central];
            
        }
        else if(pedido() == carga)
        {
            distancia += vCostes[proximoCliente];
            vector<unsigned> vuelta = Dijkstra(G, proximoCliente, vVer);
            distancia += vuelta[central];
        }

    }
}