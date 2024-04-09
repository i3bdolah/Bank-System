#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

class String
{
private:
	string _value;

public:
	String() {
		_value = "";
	}
	String(string str) {
		_value = str;
	}

	void setValue(string str) {
		_value = str;
	}
	string getValue() {
		return _value;
	}

	__declspec(property(get = getValue, put = setValue)) string value;

	// _______________________ Library _______________________

	static string EnterString(string temp) {
		cout << "Enter The String : " << endl;
		getline(cin, temp);

		return temp;
	}

	string EnterString() {
		return EnterString(_value);
	}

	static int Length(string str) {
		return str.length();
	}

	int Length() {
		return Length(_value);
	}

	static string FirstInWords(string str) {
		bool isFirstLetter = true;
		string result = "";

		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] != ' ' && isFirstLetter)
			{
				result = result + str[i];
			}

			isFirstLetter = (str[i] == ' ' ? true : false);
		}
		return result;
	}

	string FirstInWords() {
		return FirstInWords(_value);
	}

	static string UpperAllFirsts(string str) {
		bool isFirstLetter = true;

		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] != ' ' && isFirstLetter)
			{
				str[i] = toupper(str[i]);
			}

			isFirstLetter = (str[i] == ' ' ? true : false);
		}
		return str;
	}

	string UpperAllFirsts() {
		return UpperAllFirsts(_value);
	}

	static string LowerAllFirsts(string str) {
		bool isFirstLetter = true;

		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] != ' ' && isFirstLetter)
			{
				str[i] = tolower(str[i]);
			}

			isFirstLetter = (str[i] == ' ' ? true : false);
		}
		return str;
	}

	string LowerAllFirsts() {
		return LowerAllFirsts(_value);
	}

	static string LowerAll(string str) {
		bool isFirstLetter = true;

		for (int i = 0; i < str.length(); i++)
		{
			str[i] = tolower(str[i]);
		}
		return str;
	}

	string LowerAll() {
		return LowerAll(_value);
	}

	static string UpperAll(string str) {
		bool isFirstLetter = true;

		for (int i = 0; i < str.length(); i++)
		{
			str[i] = toupper(str[i]);
		}
		return str;
	}

	string UpperAll() {
		return UpperAll(_value);
	}

	static char InvertCase(char chr) {
		return isupper(chr) ? tolower(chr) : toupper(chr);
	}

	static string InvertAll(string str) {
		for (int i = 0; i < str.length(); i++)
		{
			str[i] = InvertCase(str[i]);
		}
		return str;
	}

	string InvertAll() {
		return InvertAll(_value);
	}

	static bool IsLower(char chr) {
		return (char(chr) >= 97 && char(chr) <= 122) ? true : false;
	}

	static bool IsUpper(char chr) {
		return (char(chr) >= 65 && char(chr) <= 90) ? true : false;
	}

	static int CountUpper(string str) {
		int uppercase = 0;

		for (int i = 0; i < str.length(); i++)
		{
			if (IsUpper(str[i]))
			{
				uppercase++;
			}
		}
		return uppercase;
	}

	int CountUpper() {
		return CountUpper(_value);
	}

	static int CountLower(string str) {
		int lowercase = 0;

		for (int i = 0; i < str.length(); i++)
		{
			if (IsLower(str[i]))
			{
				lowercase++;
			}
		}
		return lowercase;
	}

	int CountLower() {
		return CountLower(_value);
	}

	static int CountLetter(string str, char chr) {
		int count = 0;
		string str_temp = LowerAll(str);
		char chr_temp = tolower(chr);


		for (int i = 0; i < str_temp.length(); i++)
		{
			if (str_temp[i] == chr_temp)
			{
				count++;
			}
		}
		return count;
	}

	int CountLetter(char Letter) {
		return CountLetter(_value, Letter);
	}

	static bool IsVowel(char chr) {
		char lowerChr = tolower(chr);

		return (lowerChr == 'a' || lowerChr == 'e' || lowerChr == 'i' || lowerChr == 'o' || lowerChr == 'u');
	}

	static int CountVowel(string str) {
		int counter = 0;

		for (int i = 0; i < str.length(); i++)
		{
			if (IsVowel(str[i]))
			{
				counter++;
			}
		}
		return counter;
	}

	int CountVowel() {
		return CountVowel(_value);
	}

	static void PrintWordSeparately(string str) {

		string delim = " ";
		string stringInRange = "";
		int pos = 0;

		while ((pos = str.find(delim)) != string::npos)
		{
			stringInRange = str.substr(0, pos);
			if (stringInRange != " ")
			{
				cout << "{" << stringInRange << "}, ";
			}

			str.erase(0, pos + delim.length());
		}
		if (str != "")
		{
			cout << "{" << str << "}; " << endl;
		}
	}

	void PrintWordSeparately() {
		return PrintWordSeparately(_value);
	}

	static short CountWords(string str) {

		string delim = " ";
		string stringInRange = "";
		int pos = 0;
		int counter = 0;

		while ((pos = str.find(delim)) != string::npos)
		{
			stringInRange = str.substr(0, pos);
			if (stringInRange != "")
			{
				//cout << '|' << stringInRange << '|' << endl;
				counter++;
			}

			str.erase(0, pos + delim.length());
		}
		if (str != "")
		{
			//cout << '|' << str << '|' << endl;
			counter++;
		}
		return counter;
	}

	short CountWords() {
		return CountWords(_value);
	}

	static vector <string> Split(string sentence, string separator) {
		vector <string> wordsSeparated;
		int pos = 0;
		string strTemp;

		while ((pos = sentence.find(separator)) != string::npos)
		{
			strTemp = sentence.substr(0, pos);
			if (strTemp != separator)
			{
				wordsSeparated.push_back(strTemp.substr(0, (pos)));
			}

			sentence.erase(0, pos + separator.length());
		}

		if (sentence != "" && sentence != separator)
		{
			wordsSeparated.push_back(sentence);
		}

		return wordsSeparated;
	}

	vector <string> Split(string separator) {
		return Split(_value, separator);
	}

	static void PrintStringVector(vector <string> vector) {

		cout << '\n';
		cout << "Size = " << vector.size() << endl;
		for (string& elementInVector : vector)
		{
			cout << '|' << elementInVector << '|' << endl;
		}
	}

	static string TrimRight(string str) {
		int lastIndex = str.length() - 1;
		while (str[lastIndex] == ' ')
		{
			str.erase(lastIndex);
			lastIndex = str.length() - 1;
		}
		return str;
	}

	string TrimRight() {
		return TrimRight(_value);
	}

	static string TrimLeft(string str) {
		while (str[0] == ' ')
		{
			str.erase(0, 1);
		}
		return str;
	}

	string TrimLeft() {
		return TrimLeft(_value);
	}

	static string TrimAll(string str) {
		return TrimLeft(TrimRight(str));
	}

	string TrimAll() {
		return TrimAll(_value);
	}

	static string Join(vector <string> vector, string separator) {
		string wordsJoined;

		for (string& name : vector)
		{
			wordsJoined = wordsJoined + name + separator;
		}

		return wordsJoined.substr(0, wordsJoined.length() - separator.length());
	}

	static string Join(string arr[3], int arrLength, string separator) {
		string wordsJoined;

		for (int i = 0; i < arrLength; i++)
		{
			wordsJoined = wordsJoined + arr[i] + separator;
		}

		return wordsJoined.substr(0, wordsJoined.length() - separator.length());
	}

	static string ReverseWords(string str) {

		vector <string> vector1 = Split(str, " ");
		vector <string> newVector;

		for (int i = vector1.size() - 1; i >= 0; i--)
		{
			newVector.push_back(vector1.at(i));
		}
		return Join(newVector, " ");
	}

	string ReverseWords() {
		return ReverseWords(_value);
	}

	static string ReplaceWord(string targeted, string replacement, string allWords, bool isCaseSensitive = 1) {
		vector <string> splattedString = Split(allWords, " ");

		if (isCaseSensitive)
		{
			for (string& word : splattedString)
			{
				if (word == targeted)
				{
					word = replacement;
				}
			}
		}
		else {
			for (string& word : splattedString)
			{
				if (LowerAll(word) == LowerAll(targeted))
				{
					word = replacement;
				}
			}
		}
		return Join(splattedString, " ");
	}

	string ReplaceWord(string targeted, string replacement, bool isCaseSensitive = 1) {
		return ReplaceWord(targeted, replacement, _value, isCaseSensitive);
	}

	static string RemovePunctuations(string str) {
		for (int i = 0; i < str.length(); i++)
		{
			if (ispunct(str[i])) {
				str.erase(i, 1);
			}
		}
		return str;
	}

	string RemovePunctuations() {
		return RemovePunctuations(_value);
	}


};