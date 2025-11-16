#pragma once
#include <iostream>
using namespace std;
#include "PaymentMethod.h"
#include "IAuthentification.h"
#include "IRechargement.h"

class Crypto : virtual public PaymentMethod, public IAuthentification, public IRechargement
{
private:
	string blockchain;
	string cle;
public:
	Crypto(string nom="", string idd = "", double bal = 200.00, string block = "", string cle = "");
	virtual bool payer(double montant) ;
	virtual bool authenticate();
	virtual void recharger(double montant) override;
	virtual void display() const override;
	virtual ~Crypto();
};


