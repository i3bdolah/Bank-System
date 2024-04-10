#pragma once
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
#include <stdlib.h>     /* srand, rand */
#include "Date.h"

class Utility
{
public:
	static void Srand() {
		srand((unsigned)time(NULL));
	}

	static bool IsPrimeNumer(int num) {
		int halfNum = num / 2;

		for (int i = 2; i < halfNum; i++)
		{
			if (num % 2 == 0)
			{
				return false;
			}
		}
		return true;
	}
	static bool IsPrimeNumer(short num) {
		short halfNum = num / 2;

		for (short i = 2; i < halfNum; i++)
		{
			if (num % 2 == 0)
			{
				return false;
			}
		}
		return true;
	}

	static bool IsPerfectNumber(int num) {
		int sum = 0;

		for (int i = 1; i < num; i++)
		{
			if (num % i == 0) {
				sum += i;
			}
		}
		return num == sum;
	}
	static bool IsPerfectNumber(short num) {
		short sum = 0;

		for (short i = 1; i < num; i++)
		{
			if (num % i == 0) {
				sum += i;
			}
		}
		return num == sum;
	}

	static int ReverseInt(int num) {
		int remainder = 0;

		while (num > 0)
		{
			remainder = (remainder * 10) + num % 10; // Takes last num
			num = num / 10; // Removes last num
		}
		return remainder;
	}

	static int SumAllDigits(int num) {
		int remainder = 0;

		while (num > 0)
		{
			remainder = remainder + (num % 10);
			num = num / 10;
		}
		return remainder;
	}

	static bool IsPalindrome(int num) {
		return num == ReverseInt(num);
	}

	static string EncryptWord(string word, int encryptionKey) {
		string encryptedWord = "";

		for (int i = 0; i < word.length(); i++)
		{
			encryptedWord = encryptedWord + char(word[i] + encryptionKey);
		}

		return encryptedWord;
	}
	static string DecryptWord(string word, int encryptionKey) {
		string decryptedWord = "";

		for (int i = 0; i < word.length(); i++)
		{
			decryptedWord = decryptedWord + char(word[i] - encryptionKey);
		}

		return decryptedWord;
	}
	static void PrintEncryptionAndDecryption(string word, int encryptionKey) {
		cout << "Text Before Encryption = " << word << endl;
		cout << "Text After Encryption = " << EncryptWord(word, encryptionKey) << endl;
		cout << "Text After Decryption = " << DecryptWord(EncryptWord(word, encryptionKey), encryptionKey) << endl;
	}

	static int GenerateRandomNumber(int from, int to) {
		return rand() % (to - from + 1) + from;
	}
	static string GenerateCapitalLetters(int num) {
		string word = "";
		for (int i = 1; i <= num; i++)
		{
			word = word + char(GenerateRandomNumber(65, 90));
		}
		return word;
	}
	static string GenerateFullKey() { // Generating Key with correct formating
		return GenerateCapitalLetters(4) + "-" + GenerateCapitalLetters(4) + "-" + GenerateCapitalLetters(4) + "-" + GenerateCapitalLetters(4);
	}
	static void PrintKeys(int num) {
		for (int i = 1; i <= num; i++)
		{
			cout << "Key [" << i << "] : ";
			cout << GenerateFullKey() << endl;
		}

	}

	static void PrintArray(int arr[100], int arrLength) {
		for (int i = 0; i < arrLength; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
	}
	static string ArrayToString(int arr[100], int arrLength) {
		string str = "{ ";
		for (int i = 0; i < arrLength; i++)
		{
			str = str + to_string(arr[i]) + ", ";
		}
		str.erase(str.end() - 2, str.end());
		return str += " }";
	}
	static string ArrayToString(string arr[100], int arrLength) {
		string str = "{ ";
		for (int i = 0; i < arrLength; i++)
		{
			str = str + arr[i] + ", ";
		}
		str.erase(str.end() - 2, str.end());
		return str += " }";
	}
	static int NumberOfOccurrences(int arr[100], int arrLength, int goalNum) {
		int numOfOccurrences = 0;
		for (int i = 0; i < arrLength; i++)
		{
			if (arr[i] == goalNum)
			{
				numOfOccurrences += 1;
			}
		}
		return numOfOccurrences;
	}
	static short FindInArray(int arr[100], int arrLength, int goalNum) {
		for (int i = 0; i < arrLength; i++)
		{
			if (arr[i] == goalNum)
				return i;
		}
		return -1;
	}

	static void FillArrayRandom(int arr[100], int arrLength, int from, int to) {
		for (int i = 0; i < arrLength; i++)
		{
			arr[i] = GenerateRandomNumber(from, to);
		}
	}
	static int MaxInArray(int arr[100], int arrLength) {
		int max = 0;

		for (int i = 0; i < arrLength; i++)
		{
			if (arr[i] > max)
			{
				max = arr[i];
			}
		}
		return max;
	}
	static int MinInArray(int arr[100], int arrLength) {
		int min = arr[0];

		for (int i = 0; i < arrLength; i++)
		{
			if (arr[i] < min)
			{
				min = arr[i];
			}
		}
		return min;
	}
	static int SumInArray(int arr[100], int arrLength) {
		int sum = 0;

		for (int i = 0; i < arrLength; i++)
		{
			sum += arr[i];
		}
		return sum;
	}
	static float AvgInArray(int arr[100], int arrLength) {
		return (float)SumInArray(arr, arrLength) / arrLength;
	}
	static void CopyArray(int fArr[100], int lArr[100], int arrLength) {
		for (int i = 0; i < arrLength; i++)
		{
			lArr[i] = fArr[i];
		}
	}
	static void SumTwoArrays(int arr1[100], int arr2[100], int arrSum[100], int arrLength) {
		for (int i = 0; i < arrLength; i++)
		{
			arrSum[i] = arr1[i] + arr2[i];
		}
	}
	static void FillArrayOrdered(int arr[100], int arrLength) {
		for (int i = 0; i < arrLength; i++)
		{
			arr[i] = i + 1;
		}
	}
	static void ShuffleArray(int arr[100], int arrLength) {
		int num1, num2;
		int temp = 0;

		for (int i = 0; i < arrLength; i++)
		{
			num1 = GenerateRandomNumber(0, arrLength - 1);
			num2 = GenerateRandomNumber(0, arrLength - 1);

			temp = arr[num1];
			arr[num1] = arr[num2];
			arr[num2] = temp;
		}
	}
	static void CopyArrayReversed(int toArr[100], int fromArr[100], int arrLength) {
		for (int i = 0; i < arrLength; i++)
		{
			toArr[i] = fromArr[(arrLength - 1) - i];
		}
	}
	static void FillArrayKeys(string arr[100], int arrLength) {
		for (int i = 0; i < arrLength; i++)
		{
			arr[i] = GenerateFullKey();
		}

	}
	static bool IsDistinct(int arr[100], int arrLength, int goalNum) {
		return FindInArray(arr, arrLength, goalNum) == -1;
	}
	static short CountOddInArray(int arr[100], int arrLength) {
		short oddCounts = 0;
		for (int i = 0; i < arrLength; i++)
		{
			if (arr[i] % 2 != 0)
				oddCounts++;
		}
		return oddCounts;
	}
	static short CountEvenInArray(int arr[100], int arrLength) {
		short evenCounts = 0;
		for (int i = 0; i < arrLength; i++)
		{
			if (arr[i] % 2 == 0)
				evenCounts++;
		}
		return evenCounts;
	}
	static short CountPositiveInArray(int arr[100], int arrLength) {
		short positiveCounts = 0;
		for (int i = 0; i < arrLength; i++)
		{
			if (arr[i] >= 0)
				positiveCounts++;
		}
		return positiveCounts;
	}
	static short CountNegativeInArray(int arr[100], int arrLength) {
		short count = 0;
		for (int i = 0; i < arrLength; i++)
		{
			if (arr[i] < 0)
				count++;
		}
		return count;
	}

	static int Abs(int num) {
		if (num > 0)
			return num;
		else
			return num * -1;
	}
	static float Floor(float num) {
		if (num > 0)
		{
			return int(num);
		}
		else {
			return int(num) - 1;
		}
	}
	static double Floor(double num) {
		if (num > 0)
		{
			return int(num);
		}
		else {
			return int(num) - 1;
		}
	}
	static float Ceil(float num) {
		if (num > 0)
		{
			return int(num) + 1;
		}
		else {
			return int(num);
		}
	}
	static double Ceil(double num) {
		if (num > 0)
		{
			return int(num) + 1;
		}
		else {
			return int(num);
		}
	}
	static float Sqrt(float num) {
		return pow(num, 0.5);
	}
	static double Sqrt(double num) {
		return pow(num, 0.5);
	}

	static float GetFraction(float num) {
		return num - (int)num;
	}
	static double GetFraction(double num) {
		return num - (int)num;
	}

	static void Swap(string& value1, string& value2) {
		string temp = value1;
		value1 = value2;
		value2 = temp;
	}
	static void Swap(int& value1, int& value2) {
		int temp = value1;
		value1 = value2;
		value2 = temp;
	}
	static void Swap(short& value1, short& value2) {
		short temp = value1;
		value1 = value2;
		value2 = temp;
	}
	static void Swap(float& value1, float& value2) {
		float temp = value1;
		value1 = value2;
		value2 = temp;
	}
	static void Swap(double& value1, double& value2) {
		double temp = value1;
		value1 = value2;
		value2 = temp;
	}
	static void Swap(char& value1, char& value2) {
		char temp = value1;
		value1 = value2;
		value2 = temp;
	}
	static void Swap(Date& value1, Date& value2) {
		Date::SwapTwoDates(value1, value2);
	}

	static string NumberToText(int Number)
	{

		if (Number == 0)
		{
			return "";
		}

		if (Number >= 1 && Number <= 19)
		{
			string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
		"Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
		  "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

			return  arr[Number] + " ";

		}

		if (Number >= 20 && Number <= 99)
		{
			string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
			return  arr[Number / 10] + " " + NumberToText(Number % 10);
		}

		if (Number >= 100 && Number <= 199)
		{
			return  "One Hundred " + NumberToText(Number % 100);
		}

		if (Number >= 200 && Number <= 999)
		{
			return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
		}

		if (Number >= 1000 && Number <= 1999)
		{
			return  "One Thousand " + NumberToText(Number % 1000);
		}

		if (Number >= 2000 && Number <= 999999)
		{
			return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
		}

		if (Number >= 1000000 && Number <= 1999999)
		{
			return  "One Million " + NumberToText(Number % 1000000);
		}

		if (Number >= 2000000 && Number <= 999999999)
		{
			return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
		}

		if (Number >= 1000000000 && Number <= 1999999999)
		{
			return  "One Billion " + NumberToText(Number % 1000000000);
		}
		else
		{
			return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
		}


	}

};