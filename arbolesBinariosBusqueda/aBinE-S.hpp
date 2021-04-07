#ifndef abb_E_S_H
#define abb_E_S_H

#include <cassert>
#include <iostream>
#include <fstream>
#include "Abb.hpp"


using std::istream;
using std::ostream;
using std::cin;
using std::cout;
using std::endl;

template <typename T>
void rellenarAbb(Abb<T>& A, const T& fin)
// Pre: A esta vacio.
// Post: Rellena el arbol A con la estructura y elementos
//       leidos en preorden de la entrada estandar, usando
//       fin como elemento especial para introducir nodos nulos.
{
   T e;

   assert(A.vacio());
   cout << "Raiz (Fin = " << fin << "): ";
   cin >> e;
    A.insertar(e);
   do
   {
       cout << "inserte elemento: ";
       cin >> e;
       cout<<endl;
       if (e != fin)
          A.insertar(e);
   }while(e != fin);

}

template <typename T>
void imprimirAbb  (const Abb<T>& A)
// Post: Muestra los nodos de A en la salida estandar
{
    if (!A.vacio())
    {
      cout << "Raiz del arbol: " << A.elemento() << endl;
      imprimirDescendientes(A);
    }
}

template <typename T>
void imprimirDescendientes(const Abb<T>& A)
// Post: Muestra los descendientes de r en la salida estandar.
{
    if(!A.vacio())
    {
        if (!A.izqdo().vacio())
        {
            cout << "Hijo izqdo de " << A.elemento() << ": " << A.izqdo().elemento() << endl;
            imprimirDescendientes(A.izqdo());
        }

        if (!A.drcho().vacio())
        {
            cout << "Hijo derecho de " << A.elemento() << ": " << A.drcho().elemento() << endl;
            imprimirDescendientes(A.drcho());
        }
    }
}

#endif   