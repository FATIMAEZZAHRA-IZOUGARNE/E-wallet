#pragma once
#include <iostream>
using namespace std;
#include "PaymentMethod.h"
#include "IAuthentification.h"
#include "IRechargement.h"

class Paypal : virtual public PaymentMethod, public IAuthentification, public IRechargement
{
private:
	string Email;
public:
	Paypal(string nom = "", string idd = "", double bal = 00.00, string email = "");
	virtual bool payer(double montant) ;
	virtual bool authenticate();
	virtual void recharger(double montant) override;
	virtual void display() const override;
	virtual ~Paypal();
};

