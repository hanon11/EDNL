#include <iostream>
#include "../../arbolesGenerales/aGenEnlazada.hpp"
#include <cmath>
enum Color {B, N, sin_color};
struct Cuadrante 
{
    size_t x_ini, x_fin, y_ini, y_fin;
    Cuadrante(size_t x_0, size_t x, size_t y_0, size_t y) : x_ini(x_0), x_fin(x), y_ini(y_0), y_fin(y) {};
};


void rellenaRec(const Agen<Color>& A, Agen<Color>::nodo n, Color** m, Cuadrante c)
{
    if(n != Agen<Color>::NODO_NULO)
    {
        if(A.elemento(n) == sin_color)
        {
            Agen<Color>::nodo hijo = A.hijoIzqdo(n);
            unsigned cuadrante = 0;
            // 0 1
            // 3 2
            while(hijo != Agen<Color>::NODO_NULO)
            {
                switch(cuadrante)
                {
                    case 0:
                        c.x_fin /= 2;
                        c.y_fin /= 2;
                    break;
                    case 1:
                        c.x_ini = c.x_fin + 1;
                        c.x_fin = c.x_fin*2 + 1;
                    break;
                    case 2:
                        c.y_ini = c.y_fin + 1;
                        c.y_fin = c.y_fin*2 + 1;
                    break;
                    case 3: 
                        c.x_ini = 0;
                        c.x_fin /= 2;
                    break;
                }
                rellenaRec(A, hijo, m, c);
                hijo = A.hermDrcho(hijo);
                cuadrante++;
            }
        }
        else
        {
            for(int i = c.x_ini; i <= c.x_fin; i++)
            {
                for(int j = c.y_ini; j <= c.y_fin; j++)
                {
                    m[i][j] = A.elemento(n);
                }
            }
        }
    }
}

Color** rellena(const Agen<Color>& A)
{
    unsigned alt = A.altura(A.raiz());
    alt = std::pow(2, alt);
    Color** matriz = new Color*[alt];
    for(int i = 0; i < alt; i++)
    {
        matriz[i] = new Color[alt];
    }
    
    rellenaRec(A, A.raiz(), matriz, Cuadrante(0, alt-1, 0, alt-1));
    return matriz;
}
