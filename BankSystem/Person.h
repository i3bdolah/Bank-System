#pragma once
#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
	string _FirstName;
	string _LastName;
	string _Email;
	string _Phone;

public:

	Person(string _FirstName, string _LastName, string _Email, string _Phone) {
		this->_FirstName = _FirstName;
		this->_LastName = _LastName;
		this->_Email = _Email;
		this->_Phone = _Phone;
	}

	void SetFirstName(string _FirstName) { this->_FirstName = _FirstName; }
	string GetFirstName() { return this->_FirstName; }
	__declspec(property(get = GetFirstName, put = SetFirstName)) string FirstName;

	void SetLastName(string _LastName) { this->_LastName = _LastName; }
	string GetLastName() { return this->_LastName; }
	__declspec(property(get = GetLastName, put = SetLastName)) string LastName;

	void SetEmail(string _Email) { this->_Email = _Email; }
	string GetEmail() { return this->_Email; }
	__declspec(property(get = GetEmail, put = SetEmail)) string Email;

	void SetPhone(string _Phone) { this->_Phone = _Phone; }
	string GetPhone() { return this->_Phone; }
	__declspec(property(get = GetPhone, put = SetPhone)) string Phone;

	string FullName() { return this->_FirstName + " " + this->LastName; }

	void Print()
	{
		cout << "\nInfo:";
		cout << "\n___________________";
		cout << "\nFirstName: " << _FirstName;
		cout << "\nLastName : " << _LastName;
		cout << "\nFull Name: " << FullName();
		cout << "\nEmail    : " << _Email;
		cout << "\nPhone    : " << _Phone;
		cout << "\n___________________\n";

	}
};

