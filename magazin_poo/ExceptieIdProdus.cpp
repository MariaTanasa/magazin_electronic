#include "ExceptieIdProdus.h"

const char* ExceptieIdProdus::what() const throw()
{
    return "Id-ul produsului trebuie sa fie un numar pozitiv.";
}
