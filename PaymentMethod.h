#pragma once
#include <iostream>
using namespace std;

class PaymentMethod
{
private:
	string typeM;

protected:
	string ownerName;
	string id;
	double balance;
public:
	PaymentMethod(string name = "", string id = "", double bal = 00.00, string typeM = "");
	virtual void display() const ;
	virtual bool payer(double montant) = 0;
	virtual void recharger(double montant) = 0;
	virtual ~PaymentMethod();

};

