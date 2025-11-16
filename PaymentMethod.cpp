#include "PaymentMethod.h"

PaymentMethod::PaymentMethod(string name, string id, double bal, string typeM) :ownerName(name), id(id), balance(bal), typeM(typeM)
{
}


void PaymentMethod::display() const
{
	cout << "---------------------Titulaire :" << endl;
	cout << "name : " << this->ownerName << endl;
	cout << "Id :" << this->id << endl;
	cout << "Balance :" << this->balance << endl;
	cout << "-----------La methode de paiement :" << this->typeM << endl;
}


PaymentMethod::~PaymentMethod()
{
	cout << "call for distructor of the Classe PaymentMethod " << endl;
}

