#include "ejercicios.hpp"
#include "../Abb.hpp"
#include "../aBinE-S.hpp"
const int fin = -1;

int main()
{
    Abb<int> A, B;
	A.insertar(1);
	A.insertar(2);
	A.insertar(3);
	A.insertar(4);
	A.insertar(5);
	imprimirAbb(A);
	equilibrio(A, B);
	imprimirAbb(B);
}