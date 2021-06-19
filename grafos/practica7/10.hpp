#include <iostream>
#include "../alg_grafoPMC.hpp"


template <typename tCoste>
void viaje(const GrafoP<tCoste>& tren, const GrafoP<tCoste>& bus, const GrafoP<tCoste>& avion, tCoste taxiEstacion, tCoste taxiAeropuerto,
        typename GrafoP<tCoste>::vertice origen, typename GrafoP<tCoste>::vertice destino)
{
    //tren       trenbus     trenavion
    //bustren      bus      busavion
    //aviontren   avionbus    avion
    GrafoP<tCoste> todos(tren.numVert() + bus.numVert() + avion.numVert()); //podria hacer *3 directamente porque tienen el mismo numero de vertices
    for(typename GrafoP<tCoste>::vertice i = 0; i < tren.numVert(); i++)
    {
        for(typename GrafoP<tCoste>::vertice j = 0; j < tren.numVert(); j++)
        {
            todos[i][j] = tren[i][j];
        }
    }

    for(typename GrafoP<tCoste>::vertice i = tren.numVert(), k = 0; i < tren.numVert()+bus.numVert(); i++, k++)
    {
        for(typename GrafoP<tCoste>::vertice j = tren.numVert(), l = 0; j < tren.numVert()+bus.numVert(); j++, l++)
        {
            todos[i][j] = bus[k][l];
        }
    }

    for(typename GrafoP<tCoste>::vertice i = tren.numVert()+bus.numVert(), k = 0; i < tren.numVert()+bus.numVert()+avion.numVert(); i++, k++)
    {
        for(typename GrafoP<tCoste>::vertice j = tren.numVert()+bus.numVert(), l = 0; j < tren.numVert()+bus.numVert()+avion.numVert(); j++, l++)
        {
            todos[i][j] = avion[k][l];
        }
    }
    //trenbus
    for(typename GrafoP<tCoste>::vertice i = 0; i < tren.numVert(); i++)
    {
        for(typename GrafoP<tCoste>::vertice j = tren.numVert(); j < tren.numVert()+bus.numVert(); j++)
        {
            if(j - tren.numVert() == i)
                todos[i][j] = taxiEstacion;
            
        }
    }
    //trenavion
    for(typename GrafoP<tCoste>::vertice i = 0; i < tren.numVert(); i++)
    {
        for(typename GrafoP<tCoste>::vertice j = tren.numVert()+bus.numVert(); j < tren.numVert()+bus.numVert()+avion.numVert(); j++)
        {
            if(j - tren.numVert() - bus.numVert() == i)
                todos[i][j] = taxiAeropuerto;
        }
    }
    //bustren
    for(typename GrafoP<tCoste>::vertice i = tren.numVert(); i < tren.numVert()+bus.numVert(); i++)
    {
        for(typename GrafoP<tCoste>::vertice j = 0; j < tren.numVert(); j++)
        {
            if(i - tren.numVert() == j)
                todos[i][j] = taxiEstacion;
        }
    }
    //busavion
    for(typename GrafoP<tCoste>::vertice i = tren.numVert(); i < tren.numVert()+bus.numVert(); i++)
    {
        for(typename GrafoP<tCoste>::vertice j = tren.numVert()+bus.numVert(); j < tren.numVert()+bus.numVert()+avion.numVert(); j++)
        {
            if(j - bus.numVert() == i)
                todos[i][j] = taxiAeropuerto;
        }
    }
    //aviontren
    for(typename GrafoP<tCoste>::vertice i = tren.numVert()+bus.numVert(); i < tren.numVert()+bus.numVert()+avion.numVert(); i++)
    {
        for(typename GrafoP<tCoste>::vertice j = 0; j < tren.numVert(); j++)
        {
            if(i - tren.numVert() - bus.numVert() == j)
                todos[i][j] = taxiAeropuerto;
        }
    }
    //avionbus
    for(typename GrafoP<tCoste>::vertice i = tren.numVert()+bus.numVert(); i < tren.numVert()+bus.numVert()+avion.numVert(); i++)
    {
        for(typename GrafoP<tCoste>::vertice j = tren.numVert(); j < tren.numVert()+bus.numVert(); j++)
        {
            if(i - bus.numVert() == j)
                todos[i][j] = taxiAeropuerto;
        }
    }
    //std::cout << todos << std::endl;
    vector<tCoste> trenInicio, busInicio, aviInicio;
    vector<typename GrafoP<tCoste>::vertice> vVer1(tren.numVert() + bus.numVert() + avion.numVert()), vVer2(tren.numVert() + bus.numVert() + avion.numVert()), vVer3(tren.numVert() + bus.numVert() + avion.numVert());
    trenInicio = Dijkstra(todos, origen, vVer1);
    busInicio = Dijkstra(todos, origen + tren.numVert(), vVer2);
    aviInicio = Dijkstra(todos, origen + tren.numVert() + bus.numVert(), vVer3);
    //calculo min tren(terminar en tren, terminar en bus y terminar en avion) (idem con el resto)
    tCoste minTren = std::min(trenInicio[destino], std::min(trenInicio[destino+tren.numVert()], trenInicio[destino+tren.numVert()+bus.numVert()]));
    tCoste minBus = std::min(busInicio[destino], std::min(busInicio[destino+tren.numVert()], busInicio[destino+tren.numVert()+bus.numVert()]));
    tCoste minAvion = std::min(aviInicio[destino], std::min(aviInicio[destino+tren.numVert()], aviInicio[destino+tren.numVert()+bus.numVert()]));
    tCoste minimo = std::min(minTren, std::min(minAvion, minBus));
    std::cout << "El coste minimo es " << minimo <<std::endl;
    if(minimo == minTren)
    {
        if(minimo == trenInicio[destino])
        {
            std::cout << "Ruta en tren, empezando y terminando en tren: " << std::endl;
            for(int i = 0; i < tren.numVert(); ++i)
                std::cout  << vVer1[i] << " " << std::endl;
        }
        else if(minimo == trenInicio[destino+tren.numVert()])
        {
            std::cout << "Ruta en tren, empezando en tren y terminando en bus: " << std::endl;
            for(int i = tren.numVert(); i < tren.numVert()*2; ++i)
                std::cout  << vVer1[i] << " " << std::endl;
        }
        else
        {
            std::cout << "Ruta en tren, empezando en tren y terminando en avion: " << std::endl;
            for(int i = tren.numVert()*2; i < tren.numVert()*3; ++i)
                std::cout  << vVer1[i] << " " << std::endl;
        }
    }
    else if(minimo == minBus)
    {
        if(minimo == busInicio[destino])
        {
            std::cout << "Ruta en bus, empezando en bus y terminando en tren: " << std::endl;
            for(int i = 0; i < tren.numVert(); ++i)
                std::cout  << vVer2[i] << " " << std::endl;
        }
        else if(minimo == busInicio[destino+tren.numVert()])
        {
            std::cout << "Ruta en bus, empezando y terminando en bus: " << std::endl;
            for(int i = tren.numVert(); i < tren.numVert()*2; ++i)
                std::cout  << vVer2[i] << " " << std::endl;
        }
        else
        {
            std::cout << "Ruta en bus, empezando en bus y terminando en avion: " << std::endl;
            for(int i = tren.numVert()*2; i < tren.numVert()*3; ++i)
                std::cout  << vVer2[i] << " " << std::endl;
        }
    }
    else
    {
        if(minimo == aviInicio[destino])
        {
            std::cout << "Ruta en avion, empezando en avion y terminando en tren: " << std::endl;
            for(int i = 0; i < tren.numVert(); ++i)
                std::cout  << vVer3[i] << " " << std::endl;
        }
        else if(minimo == aviInicio[destino+tren.numVert()])
        {
            std::cout << "Ruta en avion, empezando avion y terminando en bus: " << std::endl;
            for(int i = tren.numVert(); i < tren.numVert()*2; ++i)
                std::cout  << vVer3[i] << " " << std::endl;
        }
        else
        {
            std::cout << "Ruta en avion, empezando y terminando en avion: " << std::endl;
            for(int i = tren.numVert()*2; i < tren.numVert()*3; ++i)
                std::cout  << vVer3[i] << " " << std::endl;
        }
    }
}