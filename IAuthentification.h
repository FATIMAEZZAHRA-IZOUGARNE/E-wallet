#pragma once
#include <iostream>
using namespace std;

class IAuthentification
{
public:
	virtual bool authenticate() = 0;   // méthode pure - interface
	virtual ~IAuthentification() = default; 
};

