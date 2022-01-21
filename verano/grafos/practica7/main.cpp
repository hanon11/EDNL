#include <iostream>
#include "../../../grafos/alg_grafoPMC.hpp"
#include "../../../grafos/alg_grafo_E-S.hpp"
#include "laberinto3D.hpp"
#include <vector>
int main()
{
    /*GrafoP<unsigned> G1("1.dat");
    std::cout << "El grafo\n" << G1 << std::endl;
    Viaje<unsigned> viaje = calcularViajeCaro(G1);
    std::cout << "Costes: " << viaje.coste << "\nOrigen: " << viaje.origen << "\nDestino: " << viaje.destino << std::endl;

    casilla c1(0,0), c2(2,2);
    Lista<pared> lista;
    pared p, p2;
    p.origen = 1; p.destino = 4;
    p2.origen = 5; p2.destino = 8;
    lista.insertar(p,lista.fin());
    lista.insertar(p2,lista.fin());
    vector<casilla> ruta = laberinto(3, lista, c1, c2);
    vector<casilla>::iterator pos = ruta.begin();
    while(pos != ruta.end())
    {
        std::cout << "Fila: " << pos->fila << " Columna: " << pos->columna <<std::endl;
        pos++;
    }
    casilla c1(0,0,0), c2(2,2, 2);
    vector<std::size_t> piedras;
    piedras.insert(piedras.begin(), 9);
    piedras.insert(piedras.begin(), 24);
    laberinto3D(3, piedras, c1, c2);
    GrafoP<double> G3("3.dat");
    vector<unsigned> almacenamiento;
    almacenamiento.insert(almacenamiento.begin(), 10);
    almacenamiento.insert(almacenamiento.begin(), 20);
    almacenamiento.insert(almacenamiento.begin(), 100);
    almacenamiento.insert(almacenamiento.begin(), 700);
    vector<double> porcentajes;
    porcentajes.insert(porcentajes.begin(), 10);
    porcentajes.insert(porcentajes.begin(), 0);
    porcentajes.insert(porcentajes.begin(), 10);
    porcentajes.insert(porcentajes.begin(), 1);
    distribucion(G3, 0, almacenamiento, porcentajes, 70);*/
    /*GrafoP<unsigned> G4("4.dat");
    Parte p1;
    p1.carga = 3;
    p1.ciudad = 1;
    vector<Parte> partes;
    partes.insert(partes.begin(), p1);
    GrafoP<unsigned>::vertice capital = 0;
    cementosZuelandia(G4, partes, capital);*/

    /*GrafoP<unsigned> avion("5avion.dat");
    GrafoP<unsigned> tren("5tren.dat");
    GrafoP<unsigned> carretera("5carretera.dat");
    GrafoP<unsigned>::vertice salida = 0;
    Alergia alergia = T;
    viajeroAlergico(carretera, tren, avion, (double)200, alergia, salida);*/
    /*GrafoP<unsigned> tren("6tren.dat");
    GrafoP<unsigned> bus("6bus.dat");
    GrafoP<unsigned>::vertice ciudad = 0;
    viaje(bus, tren, ciudad);*/
    /*GrafoP<unsigned> tren("7tren.dat");
    GrafoP<unsigned> bus("7bus.dat");
    GrafoP<unsigned>::vertice origen = 0, destino = 4, cambio1 = 2, cambio2 = 3;
    origenDestino(tren, bus, origen, destino, cambio1, cambio2);*/
    /*GrafoP<unsigned> tren("8tren.dat");
    GrafoP<unsigned> bus("8bus.dat");
    GrafoP<unsigned>::vertice origen = 0, destino = 3;
    unSoloTransbordo(tren, bus, origen, destino);*/
   /* GrafoP<unsigned> tren("8tren.dat");
    GrafoP<unsigned> bus("8bus.dat");
    GrafoP<unsigned>::vertice origen = 0, destino = 3;
    viaje(tren, bus, origen, destino, 3);*/
    /*GrafoP<unsigned> isla1("11isla1.dat");
    GrafoP<unsigned> isla2("11isla2.dat");
    GrafoP<unsigned> isla3("11isla3.dat");
    vector<Puente> puentes;
    Puente p1; p1.origen = 0; p1.destino = 3;
    puentes.insert(puentes.begin(), p1);
    tresIslas(isla1, isla2, isla3, puentes);*/
    /*GrafoP<unsigned> tren("10tren.dat");
    GrafoP<unsigned> bus("10bus.dat");
    GrafoP<unsigned> avion("10avion.dat");
    GrafoP<unsigned>::vertice origen = 0, destino = 3;
    viaje(tren, bus, avion, (unsigned)3, (unsigned)2, origen, destino);
    ViajeTriple(0, 3, 3, 2);*/
    /*GrafoP<unsigned> fobos("fobos.dat");
    GrafoP<unsigned> deimos("deimos.dat");
    vector<GrafoP<unsigned>::vertice> costerasFobos, costerasDeimos;
    costerasDeimos.insert(costerasDeimos.begin(), 0);
    costerasFobos.insert(costerasFobos.begin(), 2);
    grecoland(fobos, deimos, costerasFobos, costerasDeimos);*/
    casilla c1, c2;
    c1.fila = 0; c1.columna = 0; c1.profundidad = 0;
    c2.fila = 2; c2.columna = 2; c2.profundidad = 2;
    vector<pared> lista;
    pared p1, p2;
    p1.origen = 24; p1.destino = 25;
    p2.origen = 0; p2.destino = 9;
    lista.insert(lista.end(), p1);
    lista.insert(lista.end(), p2);
    laberinto(3, lista, c1, c2);
}
