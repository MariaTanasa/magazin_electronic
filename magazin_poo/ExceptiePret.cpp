#include "ExceptiePret.h"

const char* ExceptiePret::what() const throw()
{
	return "Error: pretul trebuie sa fie un numar pozitiv.\n";
}