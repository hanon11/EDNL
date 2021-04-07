#include "ejercicios.hpp"
#include "../Abb.hpp"
#include "../aBinE-S.hpp"
const int fin = -1;

int main()
{
    Abb<int> A, B;
	A.insertar(8);
	A.insertar(6);
	A.insertar(12);
	A.insertar(10);
	A.insertar(4);
	A.insertar(2);
	A.insertar(7);
	imprimirAbb(A);
	podaRec(6, A);
	std::cout << "Despues de la poda: ";
	imprimirAbb(A);
}