#include <iostream>
#include "../arbolesBinarios/aBinEnlazada.hpp"

typedef std::string Simbolo;
enum conectivaLogica {Y, NO, O};
union proposicion 
{
    Simbolo s_; 
    conectivaLogica c_;
};

