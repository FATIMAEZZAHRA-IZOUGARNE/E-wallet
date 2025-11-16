#pragma once
#include <iostream>
using namespace std;
#include "PaymentMethod.h"
#include "IAuthentification.h"
#include "IRechargement.h"

class Cheque : virtual public PaymentMethod, public IAuthentification, public IRechargement
{
private:
	string number;
	string bankname;
	string signature;
public:
	Cheque(string owner = "", string id = "", double bal=100, string num = "", string bankn = "", string sign = "");
	virtual void display() const override;
	virtual bool payer(double montant) ;
	virtual bool authenticate();
	virtual void recharger(double montant) override;
	virtual ~Cheque();
};


