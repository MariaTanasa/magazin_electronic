#pragma once
#include<iostream>
using namespace std;
class ExceptieIdProdus :public exception
{
public:
	const char* what() const throw();

};
