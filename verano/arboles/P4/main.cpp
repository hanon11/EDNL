#include "1.hpp"
#include "../../../arbolesBinariosBusqueda/Abb.hpp"
#include "../../../arbolesBinariosBusqueda/aBinE-S.hpp"

int main()
{
    Abb<int> A, B;
	A.insertar(1);
	A.insertar(2);
	A.insertar(3);
	A.insertar(4);
	A.insertar(5);
	B.insertar(5);
	B.insertar(7);
	Abb<int> C = diferencia(A, B);
	imprimirAbb(C);
	
}