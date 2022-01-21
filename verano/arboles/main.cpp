#include <iostream>
#include <fstream>
//#include "../../arbolesBinarios/aBinEnlazada.hpp"
#include "../../arbolesGenerales/aGenEnlazada.hpp"
#include "../../arbolesGenerales/agen_E-S.hpp"
//#include "../../arbolesBinarios/aBinE-S.hpp"
//#include "1.hpp"
#include "abinR.hpp"

int main ()
{
    /*Agen<Color> A;
    A.insertarRaiz(sin_color);
    A.insertarHijoIzqdo(A.raiz(),sin_color);
    A.insertarHijoIzqdo(A.hijoIzqdo(A.raiz()),B);
    A.insertarHermDrcho(A.hijoIzqdo(A.hijoIzqdo(A.raiz())),B);
    A.insertarHermDrcho(A.hermDrcho(A.hijoIzqdo(A.hijoIzqdo(A.raiz()))),N);
    A.insertarHermDrcho(A.hermDrcho(A.hermDrcho(A.hijoIzqdo(A.hijoIzqdo(A.raiz())))),B);
    A.insertarHermDrcho(A.hijoIzqdo(A.raiz()), N);
    A.insertarHermDrcho(A.hermDrcho(A.hijoIzqdo(A.raiz())), B);
    A.insertarHermDrcho(A.hermDrcho(A.hermDrcho(A.hijoIzqdo(A.raiz()))), N);
    //imprimirAgen(A);
    Color** m = rellena(A);
    for(int i = 0; i < pow(2, A.altura(A.raiz())); i++)
    {
        for(int j = 0; j < pow(2, A.altura(A.raiz())); j++)
        {
            switch(m[i][j])
            {
                case B:
                    std::cout << "B";
                break;
                case N:
                    std::cout << "N";
                    break;
                default:
                    break;
            }
        }
        std::cout << std::endl;
    }*/
    AbinVec<char> A(3);
    A.insertarRaiz('a');
    A.insertarHijoIzqdo(A.raiz(), 'b');
    A.insertarHijoIzqdo(A.hijoIzqdo(A.raiz()), 'd');
    A.insertarHijoDrcho(A.hijoIzqdo(A.hijoIzqdo(A.raiz())), 'i');
    A.insertarHijoDrcho(A.hijoIzqdo(A.raiz()), 'e');
    A.insertarHijoDrcho(A.hijoDrcho(A.hijoIzqdo(A.raiz())), 'd');
    A.insertarHijoDrcho(A.raiz(), 'c');
} 
