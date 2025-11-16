#include "Carte_bancaire.h"
#include "PaymentMethod.h"
#include "IAuthentification.h"
#include "IRechargement.h"

Carte_bancaire::Carte_bancaire(string nom, string idd, double sol, string num, int code, double plaf)
	:PaymentMethod(nom, id, sol, "Carte_bancaire"), numeroCompte(num), codePIN(code), plafond(plaf)
{
}

void Carte_bancaire::display() const
{
	cout << "*******************Les infos sur La carte bancaire :" << endl;
	cout << "Numero de Compte :" << this->numeroCompte << endl;
	cout << "Le code :" << this->codePIN<< endl;
	cout << "Plafond :" << this->plafond << endl;

}

//------------- Authentification
bool Carte_bancaire::authenticate()
{
	cout << "_____Autentification_____ : " << endl;
	int pin;
	cout << "Entrer le code PIN :";
	cin >> pin;
	return pin == this->codePIN;
}
//----------recherge
void Carte_bancaire::recharger(double montant)
{
	if (montant > 0) {
		this->balance += montant;
		cout << "Recharge effectuée ~~ Nouveau solde :" << this->balance << endl;
	}
}
//---------------------- payer
bool Carte_bancaire::payer(double montant) 
{
	cout << "-----------> Payer avec Une Carte bancaire " << endl;

	if (!authenticate()) {
		cout << "Échec d’authentification !" << endl;
		return false;
	}
	if (this->plafond < montant && this->balance >= montant) {
		cout << "paye avec succes ~~~ " << endl;
		cout << "Votre solde qui rest :" << (this->balance -= montant) << endl;
		return true;

	}
	
	cout << "transaction refuse .vous avez depasser la plafond !!!" << endl;
	return false;

}

Carte_bancaire::~Carte_bancaire()
{
	cout << "call for destructor of the Classe Catre_bancaire" << endl;
}


