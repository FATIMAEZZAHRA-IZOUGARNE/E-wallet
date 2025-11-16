#include "Crypto.h"
#include "PaymentMethod.h"
#include "IAuthentification.h"
#include "IRechargement.h"


Crypto::Crypto(string nom, string idd, double bal, string block, string cle)
	:PaymentMethod(nom,idd, bal, "Crypto")
{
	this->blockchain = block;
	this->cle = cle;
}

//----- authentification 
bool Crypto::authenticate()
{
	cout << "____Authentification___" << endl;
	string cleprive;
	cout << "Entrer la Cle prive :";
	cin >> cleprive;
	return cleprive == this->cle;
}
//-----recharger
void Crypto::recharger(double montant)
{
	if (montant > 0) {
		this->balance += montant;
		cout << "Recharge effectuée ~~ Nouveau solde :" << this->balance << endl;
	}
}
//-----payer
bool Crypto::payer(double montant)
{
	cout << "-------------- payer avec Crypto :" << endl;
	if (!authenticate()) {
		cout << "Échec d’authentification !" << endl;
		return false;
	}
	if (this->balance >= montant) {
		cout << "paye avec succes ~~" << endl;
		cout << "le balance qui reste :" << (this->balance -= montant) << endl;
		return true;
	}
	cout << "transaction refuse . balance insuffisant !" << endl;
	return false;

}

void Crypto::display() const
{
	cout << "-------------- about Crypto :" << endl;
	cout << "blockchain :" << this->blockchain << endl;
	cout << "cle prive :" << this->cle << endl;
}

Crypto::~Crypto()
{
	cout << "call for destructor of the classe Crypto ." << endl;
}



