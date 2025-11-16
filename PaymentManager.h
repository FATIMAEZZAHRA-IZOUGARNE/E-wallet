#pragma once
#include <iostream>
#include "PaymentMethod.h"
using namespace std;

class PaymentManager
{
private:
	PaymentMethod** methods;
	int count;
	int capacity;
public:
	PaymentManager(int cap);
	void ajoutMethod(PaymentMethod* method);
	virtual void display() const;
	virtual ~PaymentManager();
};
