#pragma once
#include <iostream>
using namespace std;

class IRechargement
{
public:
	virtual void recharger(double montant) = 0;
	virtual ~IRechargement() = default;
};

