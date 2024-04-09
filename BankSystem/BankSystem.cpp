#include <iostream>
#include "BankClient.h"
using namespace std;

int main()
{
    BankClient Client1 = BankClient::Find("A101");
    Client1.Print();

    BankClient Client2 = BankClient::Find("A102", "1234");
    Client2.Print();

    BankClient Client3 = BankClient::Find("A1023", "1234");
    Client3.Print();


    cout << "\Client3.IsEmpty() : " << Client3.IsEmpty() << endl;
    cout << "\nBankClient::IsClientExist : " << BankClient::IsClientExist("A101") << endl;
    cout << "\nBankClient::IsClientExist : " << BankClient::IsClientExist("0") << endl;
}