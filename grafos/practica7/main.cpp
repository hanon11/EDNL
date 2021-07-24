#include "../alg_grafoPMC.hpp"
#include "../alg_grafo_E-S.hpp"
#include "1.hpp"
//#include "2.hpp"
#include "3.hpp"
#include "4.hpp"
#include "5.hpp"
//#include "6.hpp"
#include "7.hpp"
#include "8.hpp"
#include "9.hpp"
#include "10.hpp"
#include "11.hpp"
#include "12.hpp"
#include "laberinto3D.hpp"
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
    }*/
    casilla c1(0,0,0), c2(2,2, 2);
    vector<std::size_t> piedras;
    piedras.insert(piedras.begin(), 9);
    piedras.insert(piedras.begin(), 24);
    laberinto3D(3, piedras, c1, c2);
    /*GrafoP<double> G3("3.dat");
    vector<unsigned> almacenamiento;
    almacenamiento.insert(almacenamiento.begin(), 100);
    almacenamiento.insert(almacenamiento.begin(), 200);
    almacenamiento.insert(almacenamiento.begin(), 100);
    almacenamiento.insert(almacenamiento.begin(), 700);
    vector<double> porcentajes;
    porcentajes.insert(porcentajes.begin(), 20);
    porcentajes.insert(porcentajes.begin(), 0);
    porcentajes.insert(porcentajes.end(), 10);
    porcentajes.insert(porcentajes.end(), 100);
    distribucion(0, 23, G3, almacenamiento, porcentajes);*/
    /*GrafoP<unsigned> G4("4.dat");
    parte p1;
    p1.carga = 3;
    p1.destino = 2;
    vector<parte> partes;
    partes.insert(partes.begin(), p1);
    GrafoP<unsigned>::vertice capital = 0;
    unsigned total = cementosZuelandia(G4, partes, capital);
    std::cout << total << std::endl;  */
    /*GrafoP<unsigned> avion("5avion.dat");
    GrafoP<unsigned> tren("5tren.dat");
    GrafoP<unsigned> carretera("5carretera.dat");
    GrafoP<unsigned>::vertice salida = 0;
    vector<int> ciudades = viajeroAlergico(carretera, tren, avion, 0, salida, (unsigned)200);
    std::cout << ciudades << std::endl;*/
    /*GrafoP<unsigned> tren("6tren.dat");
    GrafoP<unsigned> bus("6bus.dat");
    GrafoP<unsigned>::vertice ciudad = 0;
    tarifaMin(bus, tren, ciudad);*/
    /*GrafoP<unsigned> tren("7tren.dat");
    GrafoP<unsigned> bus("7bus.dat");
    GrafoP<unsigned>::vertice origen = 0, destino = 4, cambio1 = 2, cambio2 = 3;
    origenDestino(tren, bus, origen, destino, cambio1, cambio2);*/
    /*GrafoP<unsigned> tren("8tren.dat");
    GrafoP<unsigned> bus("8bus.dat");
    GrafoP<unsigned>::vertice origen = 0, destino = 3;
    unSoloTrasbordo(tren, bus, origen, destino);*/
    /*GrafoP<unsigned> tren("8tren.dat");
    GrafoP<unsigned> bus("8bus.dat");
    GrafoP<unsigned>::vertice origen = 0, destino = 3;
    calculaCamino(tren, bus, origen, destino, 3);*/
    /*GrafoP<unsigned> isla1("11isla1.dat");
    GrafoP<unsigned> isla2("11isla2.dat");
    GrafoP<unsigned> isla3("11isla3.dat");
    vector<puente<unsigned> > puentes;
    puente<unsigned> p1; p1.ciudad1 = 0; p1.ciudad2 = 3;
    puentes.insert(puentes.begin(), p1);
    calculoHuries(isla1, isla2, isla3, puentes);*/
    /*GrafoP<unsigned> tren("10tren.dat");
    GrafoP<unsigned> bus("10bus.dat");
    GrafoP<unsigned> avion("10avion.dat");
    GrafoP<unsigned>::vertice origen = 0, destino = 3;
    viaje(tren, bus, avion, (unsigned)3, (unsigned)2, origen, destino);
    //ViajeTriple(0, 3, 3, 2);
    GrafoP<unsigned> fobos("fobos.dat");
    GrafoP<unsigned> deimos("deimos.dat");
    vector<GrafoP<unsigned>::vertice> costerasFobos, costerasDeimos;
    costerasDeimos.insert(costerasDeimos.begin(), 0);
    costerasFobos.insert(costerasFobos.begin(), 2);
    std::cout << "Luxita la truxita:\n";
    grecoland(fobos, deimos, costerasFobos, costerasDeimos);*/
    
}
