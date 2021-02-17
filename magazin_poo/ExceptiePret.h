#pragma once
#include<iostream>

using namespace std;
class ExceptiePret : public exception
{
public:
	const char* what() const throw();

};