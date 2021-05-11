/*--------------------------------------------------------*/
/* particion.cpp                                          */
/*                                                        */
/* Implementaci�n de la clase Particion:                  */
/* Bosque de �rboles con uni�n por altura y b�squeda con  */
/* compresi�n de caminos.                                 */
/*--------------------------------------------------------*/

#include "particion.hpp"

// El �rbol con mayor altura se convierte en sub�rbol del otro.
void Particion::unir(int a, int b)
{
   if (padre[b] < padre[a])
      padre[a] = b;
   else {
      if (padre[a] == padre[b])
         padre[a]--; // El �rbol resultante tiene un nivel m�s.
      padre[b] = a;
   }
}

int Particion::encontrar(int x) const
{
   int y, raiz = x;

   while (padre[raiz] > -1)
      raiz = padre[raiz];
   // Compresi�n del camino de x a ra�z: Los nodos
   // del camino se hacen hijos de la ra�z
   while (padre[x] > -1) {
      y = padre[x];
      padre[x] = raiz;
      x = y;
   }
   return raiz;
}
