#pragma once
#include <iostream>
#include "Screen.h"
#include "InputValidation.h"
#include "BankClient.h"
#include "String.h"

using namespace std;

class TransferLogScreen : protected Screen
{
private:

	static void _PrintTransferLogLine(string Line) {

		vector <string> vLine = String::Split(Line, "#//#");

		cout << "| " << left << setw(25) << vLine[0];
		cout << "| " << left << setw(12) << vLine[1];
		cout << "| " << left << setw(12) << vLine[2];
		cout << "| " << left << setw(12) << stod(vLine[3]);
		cout << "| " << left << setw(12) << stod(vLine[4]);
		cout << "| " << left << setw(12) << stod(vLine[5]);
		cout << "| " << left << setw(12) << vLine[6];
		cout << '\n';
	}

public:

	static void ShowTransferLogScreen() {
		vector <string> vLines = BankClient::GetTransferLogs();
		//vector <string> vLines = {};

		string Title = "Transfer Log List";
		string Subtitle = "(" + to_string(vLines.size()) + ") Log(s).";

		_DrawScreenHeader(Title, Subtitle);
		cout << "\n-------------------------------------------------------";
		cout << "-------------------------------------------------------\n";
		cout << "| " << left << setw(25) << "Date/Time";
		cout << "| " << left << setw(12) << "S. Acc";
		cout << "| " << left << setw(12) << "R. Acc";
		cout << "| " << left << setw(12) << "Amount";
		cout << "| " << left << setw(12) << "S. Balance";
		cout << "| " << left << setw(12) << "R. Balance";
		cout << "| " << left << setw(12) << "User";
		cout << "\n-------------------------------------------------------";
		cout << "-------------------------------------------------------\n";

		if (vLines.size() == 0)
		{
			cout << "\n\t\t\t";
			cout << "Sorry, No Client Found in The Database.\n";
		}
		else
		{
			for (string& L : vLines)
			{
				_PrintTransferLogLine(L);
			}
		}
		cout << "\n-------------------------------------------------------";
		cout << "-------------------------------------------------------\n";
	}

};

