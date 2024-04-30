#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "String.h"
using namespace std;

string const CurrencyFile = "Currencies.txt";

class clsCurrency
{
private:
	enum enMode
	{
		eEmptyMode = 0,
		eUpdateMode = 1,
	};
	enMode _Mode;
	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _RateInUSD;

	static clsCurrency _ConvertLineToCurrencyObj(string Line) {
		vector <string> vLine = String::Split(Line, "#//#");

		return clsCurrency(enMode::eUpdateMode, vLine[0], vLine[1], vLine[2], stof(vLine[3]));
	}

	static string _ConvertCurrencyObjToLine(clsCurrency Obj) {
		string Line = "";

		Line += Obj.Country();
		Line += Obj.CurrencyCode();
		Line += Obj.CurrencyName();
		Line += to_string(Obj.RateInUSD());

		return Line;
	}

	static vector <clsCurrency> _LoadCurrencyDataFromFile() {
		vector <clsCurrency> vCurrencies;

		fstream MyFile;
		MyFile.open(CurrencyFile, ios::in);

		while (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				vCurrencies.push_back(_ConvertLineToCurrencyObj(Line));
			}
			MyFile.close();
		}
		return vCurrencies;
	}

	static void _SaveCurrencyDataToFile(vector <clsCurrency> vCurrencies) {
		fstream MyFile;
		MyFile.open(CurrencyFile, ios::in);

		while (MyFile.is_open())
		{
			for (clsCurrency& C : vCurrencies)
			{
				MyFile << _ConvertCurrencyObjToLine(C) << endl;
			}
			MyFile.close();
		}
	}

	void _Update() {
		vector <clsCurrency> vCurrencies = _LoadCurrencyDataFromFile();

		for (clsCurrency& C : vCurrencies)
		{
			if (this->CurrencyCode() == C.CurrencyCode())
			{
				C = *this;
				break;
			}
		}

		_SaveCurrencyDataToFile(vCurrencies);
	}

	static clsCurrency _GetEmptyCurrencyObj()
	{
		return clsCurrency(enMode::eEmptyMode, "", "", "", 0);
	}

public:

	clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float RateInUSD) {
		this->_Mode = Mode;
		this->_Country = Country;
		this->_CurrencyCode = CurrencyCode;
		this->_CurrencyName = CurrencyName;
		this->_RateInUSD = RateInUSD;
	}

	string Country() {
		return this->_Country;
	}

	string CurrencyCode() {
		return this->_CurrencyCode;
	}

	string CurrencyName() {
		return this->_CurrencyName;
	}

	float RateInUSD() {
		return this->_RateInUSD;
	}

	void UpdateRate(float NewRate) {
		this->_RateInUSD = NewRate;
		_Update();
	}

	bool IsEmpty() {
		return (this->_Mode == enMode::eEmptyMode);
	}

	static vector <clsCurrency> GetCurrenciesList() {
		return _LoadCurrencyDataFromFile();
	}

	static clsCurrency FindByCode(string CurrencyCode) {
		CurrencyCode = String::UpperAll(CurrencyCode);

		fstream MyFile;
		MyFile.open(CurrencyFile, ios::in);

		while (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency CurrentObj = _ConvertLineToCurrencyObj(Line);
				if (CurrentObj.CurrencyCode() == CurrencyCode)
				{
					MyFile.close();
					return CurrentObj;
				}
			}
			MyFile.close();
		}
		return _GetEmptyCurrencyObj();
	}

	static clsCurrency FindByCountry(string Country) {
		Country = String::UpperAll(Country);

		fstream MyFile;
		MyFile.open(CurrencyFile, ios::in);

		while (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency CurrentObj = _ConvertLineToCurrencyObj(Line);
				if (String::UpperAll(CurrentObj.Country()) == Country)
				{
					MyFile.close();
					return CurrentObj;
				}
			}
			MyFile.close();
		}
		return _GetEmptyCurrencyObj();
	}

	static bool IsCurrencyExist(string CurrencyCode) {
		clsCurrency Obj = FindByCode(CurrencyCode);
		return (!Obj.IsEmpty());
	}
};

