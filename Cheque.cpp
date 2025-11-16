#include "Cheque.h"
#include "PaymentMethod.h"
#include "IAuthentification.h"
#include "IRechargement.h"


Cheque::Cheque(string owner, string id, double bal, string num, string bankn, string sign)
	:PaymentMethod(owner, id, bal,"Cheque"), number(num), bankname(bankn), signature(sign)
{
}

void Cheque::display() const
{
	cout << "************ Infos Paiement par Chèque ************" << endl;
	cout << "Propriétaire " << this->ownerName << endl;
	cout << "ID " << this->id << endl;
	cout << "Balance :" << this->balance << endl;
	cout << "Cheque number :" << this->number << endl;
	cout << "Signature :" << this->signature << endl;
}

//-------------- auth
bool Cheque::authenticate()
{
	cout << "_______Authentification_____" << endl;
	string numcheque;
	cout << "veuillez entrer le numero de Cheque :";
	cin >> numcheque;
	return numcheque == this->number;
}
//-----------recharger
void Cheque::recharger(double montant)
{
	if (montant > 0) {
		this->balance += montant;
		cout << "Recharge effectuée ~~ Nouveau solde :" << this->balance << endl;
	}
}
//----------payer
bool Cheque::payer(double montant) 
{
	cout << "---------------------------> Payer avec Cheque" << endl;
	if (!authenticate()) {
		cout << "Echec d'authentification " << endl;
		return false;
	}
	if (this->balance >= montant) {
		cout << "paye avec succes ~~" << endl;
		cout << "le balance qui reste :" << (this->balance -= montant) << endl;
		return true;
	}
	else {
		cout << "transaction refuse . balance insuffisant !" << endl;
		return false;
	}
}



Cheque::~Cheque()
{
	cout << "call for sedtructor of the classe Cheque " << endl;
}


