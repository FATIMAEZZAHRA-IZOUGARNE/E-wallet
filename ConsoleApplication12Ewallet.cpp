// ConsoleApplication12Ewallet.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

#include "PaymentMethod.h"
#include "PaymentManager.h"
#include "Crypto.h"
#include "Carte_bancaire.h"
#include "Paypal.h"
#include "Cheque.h"
#include "IRechargement.h"
#include "IAuthentification.h"


int main()
{
    //creer le tableau des methods
    PaymentManager manager(5);

    
    //creer les methodes de paiement
    Carte_bancaire* cb = new Carte_bancaire("Ali", "carta333", 10000, "4782847464645432", 2004, 2000);
    Paypal* pp = new Paypal("Ali", "paypal001", 5000, "ali@gmail.com");
    Crypto* cry = new Crypto("Ali", "al2000", 2000, "Ethereum", "cle123");

    //ajouter au tableau manager
    manager.ajoutMethod(cb);
    manager.ajoutMethod(pp);
    manager.ajoutMethod(cry);
    manager.display();

    //tester paiement
    cb->payer(5000);
    pp->payer(4000);
    cry->payer(10000);
    cry->recharger(30000);
    cry->payer(10000);


    //Nettoyer la mémoire
    delete cb;
    delete pp;
    delete cry;


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
