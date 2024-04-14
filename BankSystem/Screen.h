#pragma once
#include <iostream>

using namespace std;

class Screen
{
protected:
	static void _DrawScreenHeader(string Title, string Subtitle = "") {
		cout << "===========================================\n";
		cout << "\t" << Title;

		if (Subtitle != "")
		{
			cout << "\n\t" << Subtitle;
		}
		cout << "\n===========================================\n\n";
	}
};

