#include "Paypal.h"
#include "PaymentMethod.h"
#include "IAuthentification.h"
#include "IRechargement.h"

Paypal::Paypal(string nom, string idd, double bal, string email)
	:PaymentMethod(nom, idd, bal, "Paypal"), Email(email)
{
}

//------authentification
bool Paypal::authenticate()
{
	string email;
	cout << "veuillez entrer votre E-mail:";
	cin >> email;
	return email == this->Email;
}
//-----------------recharger
void Paypal::recharger(double montant)
{
	if (montant > 0) {
		this->balance += montant;
		cout << "Recharge effectuée ~~ Nouveau solde :" << this->balance << endl;
	}
}

bool Paypal::payer(double montant) 
{
	cout << "-----------> Payer par l'application Paypal " << endl;
	if (!authenticate()) {
		cout << "Echec d'authentification !" << endl;
		return false;
	}

	if (this->balance >= montant) {
		cout << "paye avec succes ~~~" << endl;
		cout << "le balance qui rest :" << (this->balance -= montant) << endl;
		return true;
	}

	cout << "transaction refuse . votre solde est insuffisant !!!" << endl;
	return false;

}


void Paypal::display() const
{
	cout << "**************les infos :" << endl;
	cout << "E-mail :" << this->Email << endl;
}

Paypal::~Paypal()
{
	cout << "call for destructor of the Classe Paypal " << endl;
}


