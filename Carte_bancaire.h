#pragma once
#include <iostream>
using namespace std;
#include "PaymentMethod.h"
#include "IAuthentification.h"
#include "IRechargement.h"

class Carte_bancaire : virtual public PaymentMethod, public IAuthentification, public IRechargement
{
private:
	string numeroCompte;
	int codePIN;
	double plafond;// le montant de l'argent que je peux retire(par jour ou par mois ,...)
public:
	Carte_bancaire(string nom = "",string idd="", double sol = 00.0, string num = "", int code = 0000, double plaf = 2000);
	virtual void display() const override;
	virtual bool payer(double montant) ;
	virtual bool authenticate();
	virtual void recharger(double montant) override;
	virtual ~Carte_bancaire();
};


