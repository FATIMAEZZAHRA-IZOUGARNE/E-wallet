#include "PaymentManager.h"
#include "PaymentMethod.h"


PaymentManager::PaymentManager(int cap)
{
	this->capacity = cap;
	this->count = 0;
	this->methods = new PaymentMethod * [capacity]; //allouer dynamiquemet le tableau

}

void PaymentManager::ajoutMethod(PaymentMethod* method)
{
	if (this->count < this->capacity) {
		this->methods[this->count] = method;
		count++;
	}
	else {
		cout << "The capacity is fall !!" << endl;
	}

}
void PaymentManager::display() const
{
	cout << "-------------------> Les methodes de paiement de :" << endl;
	for (int i = 0; i < this->count; i++) {
		this->methods[i]->display();
		cout << endl;
	}
}

//destructor
PaymentManager::~PaymentManager()
{
	for (int i = 0; i < this->capacity; i++) {
		delete this->methods[i];
	}
	delete[] methods;
}


