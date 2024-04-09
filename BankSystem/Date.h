#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <ctime>
using namespace std;

class Date
{
private:
	int _year = 1;
	int _month = 1;
	int _day = 1;

	int EnterString(string msg) {
		int temp;
		cout << msg;
		cin >> temp;
		return temp;
	}
	int EnterInt(string msg) {
		int temp;
		cout << msg;
		cin >> temp;
		return temp;
	}
	Date FillDateInfo() {
		Date date;
		date.day = EnterInt("Day: ");
		date.month = EnterInt("Month: ");
		date.year = EnterInt("Year: ");
		return date;
	}

	static vector <string> splitToVector(string sentence, string separator) {
		vector <string> wordsSeperated;
		int pos = 0;
		string strTemp;

		while ((pos = sentence.find(separator)) != string::npos)
		{
			strTemp = sentence.substr(0, pos);
			if (strTemp != separator)
			{
				wordsSeperated.push_back(strTemp.substr(0, (pos)));
			}

			sentence.erase(0, pos + separator.length());
		}

		if (sentence != "" && sentence != separator)
		{
			wordsSeperated.push_back(sentence);
		}

		return wordsSeperated;
	}

	static string ReplaceWordInString(string StringToReplace, string ReplaceTo, string FullString) {
		short pos = FullString.find(StringToReplace);

		while (pos != std::string::npos) {
			FullString = FullString.replace(pos, StringToReplace.length(), ReplaceTo);
			pos = FullString.find(StringToReplace);
		}
		return FullString;
	}

public:

	Date() {
		GetSystemDate();
	}

	Date(int day, int month, int year) {
		_day = day;
		_month = month;
		_year = year;
	}

	Date(string date) {
		vector <string> vDate = splitToVector(date, "/");

		_day = stoi(vDate.at(0));
		_month = stoi(vDate.at(1));
		_year = stoi(vDate.at(2));
	}

	Date(int dayOrderInYear, int year) {
		Date date = DateFromDayOrder(dayOrderInYear, year);

		_day = date.day;
		_month = date.month;
		_year = date.year;
	}

	void Year(int num) {
		_year = num;
	}

	void Month(int num) {
		_month = num;
	}

	void Day(int num) {
		_day = num;
	}

	int GetYear() {
		return _year;
	}

	int GetMonth() {
		return _month;
	}

	int GetDay() {
		return _day;
	}

	__declspec(property(get = GetYear, put = Year)) int year;
	__declspec(property(get = GetMonth, put = Month)) int month;
	__declspec(property(get = GetDay, put = Day)) int day;


	// ______________________________


	static bool IsLeapYear(int year) {
		return ((year % 400) == 0) || ((year % 4) == 0 && (year % 100) != 0);
	}

	bool IsLeapYear() {
		return IsLeapYear(this->year);
	}

	static int DaysInYear(int year) {
		return IsLeapYear(year) ? 366 : 365;
	}

	int DaysInYear() {
		return DaysInYear(this->year);
	}

	static int HoursInYear(int year) {
		return DaysInYear(year) * 24;
	}

	int HoursInYear() {
		return HoursInYear(this->year);
	}

	static int MinsInYear(int year) {
		return HoursInYear(year) * 60;
	}

	int MinsInYear() {
		return MinsInYear(this->year);
	}

	static int SecsInYear(int year) {
		return MinsInYear(year) * 60;
	}

	int SecsInYear() {
		return SecsInYear(this->year);
	}

	static int DaysInMonth(int month, int year) {
		int NumberOfDaysInAllMonths[12] = { 31, (IsLeapYear(year) ? 29 : 28), 31, 30, 31, 30, 31 ,31, 30, 31, 30, 31 };
		return NumberOfDaysInAllMonths[month - 1];
	}

	int DaysInMonth() {
		return DaysInMonth(this->month, this->year);
	}

	static int HoursInMonth(int month, int year) {
		return DaysInMonth(month, year) * 24;
	}

	int HoursInMonth() {
		return HoursInMonth(this->month, this->year);
	}

	static int MinsInMonth(int month, int year) {
		return HoursInMonth(month, year) * 60;
	}

	int MinsInMonth() {
		return MinsInMonth(this->month, this->year);
	}

	static int SecsInMonth(int month, int year) {
		return MinsInMonth(month, year) * 60;
	}

	int SecsInMonth() {
		return SecsInMonth(this->month, this->year);
	}

	static string GetDateInString(int day, int month, int year) {
		return to_string(day) + "/" + to_string(month) + "/" + to_string(year);
	}

	string GetDateInString() {
		return GetDateInString(this->day, this->month, this->year);
	}

	static string GetDayNameByOrder(int dayOrder) {
		string DaysByIndex[7] = {
			"Sunday",
			"Monday",
			"Tuesday",
			"Wednesday",
			"Thursday",
			"Friday",
			"Saturday" };

		return DaysByIndex[dayOrder];
	}

	string GetDayNameByOrder() {
		return GetDayNameByOrder(DayOrderInWeek(*this));
	}

	static string GetMonthNameByOrder(int month) {
		string MonthsByIndex[12] = {
			"Jan", "Feb", "Mar", "Apr", "May", "Jun",
			"Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
		return MonthsByIndex[month - 1];
	}

	string GetMonthNameByOrder() {
		return GetMonthNameByOrder(this->month);
	}

	static void PrintMonthCalendar(int month, int year) {
		int NumberOfDaysInMonth = DaysInMonth(month, year);
		int DayOrder = DayOrderInWeek(1, month, year);

		printf("\n  _______________%s_______________\n\n", GetMonthNameByOrder(month).c_str());

		printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

		int i;
		for (i = 0; i < DayOrder; i++)
			printf("     ");

		for (int j = 1; j <= NumberOfDaysInMonth; j++)
		{
			printf("%5d", j);

			if (++i == 7)
			{
				i = 0;
				printf("\n");
			}
		}

		printf("\n  _________________________________\n");
	}

	void PrintMonthCalendar() {
		return PrintMonthCalendar(this->month, this->year);
	}

	static void PrintFullYearCalendar(int year) {
		printf("\n  ________________________________\n\n");
		printf("\n	_________Calendar Year__________\n\n");
		printf("\n  ________________________________\n\n");

		for (int month = 1; month <= 12; month++)
		{
			PrintMonthCalendar(month, year);
		}
	}

	void PrintFullYearCalendar() {
		return PrintFullYearCalendar(this->year);
	}

	static int DayOrderFromDate(int day, int month, int year) {
		int TotalNumberOfDays = 0;
		for (int currMonth = 1; currMonth < month; currMonth++)
		{
			TotalNumberOfDays += DaysInMonth(currMonth, year);
		}
		TotalNumberOfDays += day;

		return TotalNumberOfDays;
	}

	int DayOrderFromDate() {
		return DayOrderFromDate(this->day, this->month, this->year);
	}

	static Date DateFromDayOrder(int TotalNumberOfDays, int year) {
		Date date;
		int remainingDays = TotalNumberOfDays;
		date.year = year;

		while (true)
		{
			int currMonthDays = DaysInMonth(date.month, date.year);

			if (remainingDays > currMonthDays) {
				remainingDays -= currMonthDays;
				date.month++;
			}
			else {
				date.day = remainingDays;
				break;
			}
		}

		return date;
	}

	static Date DateAfterDaysAdded(Date date, int daysAdded) {
		while (true)
		{
			int currMonthDays = DaysInMonth(date.month, date.year);

			if ((daysAdded + date.day) > currMonthDays)
			{
				date.month++;
				if (date.month > 12) {
					date.month = 1;
					date.year++;
				}
				daysAdded -= currMonthDays;
			}
			else
			{
				date.day += daysAdded;
				break;
			}
		}
		return date;
	}

	Date DateAfterDaysAdded(int daysAdded) {
		return DateAfterDaysAdded(*this, daysAdded);
	}

	static bool IsDate1BeforeDate2(Date date1, Date date2) {
		if (date1.year < date2.year) {
			return true;
		}
		else if (date1.year == date2.year) {
			if (date1.month < date2.month)
				return true;
			else if (date1.day < date2.day)
				return true;
		}
		return false;
	}

	static bool IsDatesEquals(Date date1, Date date2) {
		return (date1.year == date2.year && date1.month == date2.month && date1.day == date2.day);
	}

	static bool IsLastDay(Date date) {
		return (date.day == DaysInMonth(date.month, date.year));
	}

	bool IsLastDay() {
		return IsLastDay(*this);
	}

	static bool IsLastMonth(int month) {
		return (month == 12);
	}

	bool IsLastMonth() {
		return IsLastMonth(this->month);
	}

	static int DateDifference(Date date1, Date date2, bool IncludeEndDay = false) {
		int diff = 0;
		int swapFlag = 1;

		if (!IsDate1BeforeDate2(date1, date2))
		{
			swapFlag = -1;
			SwapTwoDates(date1, date2);
		}

		while (IsDate1BeforeDate2(date1, date2))
		{
			date1 = IncreaseDateByOneDay(date1);
			diff++;
		}

		return (IncludeEndDay ? ++diff : diff) * swapFlag;
	}

	static Date GetSystemDate() {
		time_t t = time(0);
		tm* now = localtime(&t);

		int year = now->tm_year + 1900;
		int month = now->tm_mon + 1;
		int day = now->tm_mday;

		Date date(day, month, year);

		return date;
	}

	static int CountAllDays(Date dateAge) {
		Date DateCurrent = GetSystemDate();
		return DateDifference(dateAge, DateCurrent);
	}

	int CountAllDays() {
		return CountAllDays(*this);
	}

	static int CountAllHours(Date date) {
		return CountAllDays(date) * 24;
	}

	int CountAllHours() {
		return CountAllHours(*this);
	}

	static int CountAllMins(Date date) {
		return CountAllHours(date) * 60;
	}

	int CountAllMins() {
		return CountAllMins(*this);
	}

	static int CountAllSecs(Date date) {
		return CountAllMins(date) * 60;
	}

	int CountAllSecs() {
		return CountAllSecs(*this);
	}

	static void SwapTwoDates(Date& date1, Date& date2) {
		Date DateTemp;

		DateTemp.day = date1.day;
		DateTemp.month = date1.month;
		DateTemp.year = date1.year;

		date1.day = date2.day;
		date1.month = date2.month;
		date1.year = date2.year;

		date2.day = DateTemp.day;
		date2.month = DateTemp.month;
		date2.year = DateTemp.year;
	}

	static Date IncreaseDateByOneDay(Date date) {
		if (IsLastDay(date)) {
			date.day = 1;

			if (IsLastMonth(date.month)) {
				date.month = 1;
				date.year++;
			}
			else {
				date.month++;
			}
		}
		else
		{
			date.day++;
		}

		return date;
	}

	Date IncreaseDateByOneDay() {
		return IncreaseDateByOneDay(*this);
	}

	static Date IncreaseDateByXDays(Date date, int num) {
		while (num != 0)
		{
			date = IncreaseDateByOneDay(date);
			num--;
		}
		return date;
	}

	Date IncreaseDateByXDays(int num) {
		return IncreaseDateByXDays(*this, num);
	}

	static Date IncreaseDateByOneWeek(Date date) {
		return IncreaseDateByXDays(date, 7);
	}

	Date IncreaseDateByOneWeek() {
		return IncreaseDateByOneWeek(*this);
	}

	static Date IncreaseDateByXWeeks(Date date, int num) {
		while (num != 0)
		{
			date = IncreaseDateByOneWeek(date);
			num--;
		}
		return date;
	}

	Date IncreaseDateByXWeeks(int num) {
		return IncreaseDateByXWeeks(*this, num);
	}

	static Date IncreaseDateByOneMonth(Date date) {
		return IncreaseDateByXDays(date, DaysInMonth(date.month, date.year));
	}

	Date IncreaseDateByOneMonth() {
		return IncreaseDateByOneMonth(*this);
	}

	static Date IncreaseDateByXMonths(Date date, int num) {
		while (num != 0)
		{
			date = IncreaseDateByOneMonth(date);
			num--;
		}
		return date;
	}

	Date IncreaseDateByXMonths(int num) {
		return IncreaseDateByXMonths(*this, num);
	}

	static Date IncreaseDateByOneYear(Date date) {
		return IncreaseDateByXMonths(date, 12);
	}

	Date IncreaseDateByOneYear() {
		return IncreaseDateByOneYear(*this);
	}

	static Date IncreaseDateByXYears(Date date, int num) {
		while (num != 0)
		{
			date = IncreaseDateByOneYear(date);
			num--;
		}
		return date;
	}

	Date IncreaseDateByXYears(int num) {
		return IncreaseDateByXYears(*this, num);
	}

	static Date IncreaseDateByXYearsFaster(Date date, int num) {
		date.year += num;
		return date;
	}

	Date IncreaseDateByXYearsFaster(int num) {
		return IncreaseDateByXYearsFaster(*this, num);
	}

	static Date IncreaseDateByOneDecade(Date date) {
		return IncreaseDateByXYears(date, 10);
	}

	Date IncreaseDateByOneDecade() {
		return IncreaseDateByOneDecade(*this);
	}

	static Date IncreaseDateByXDecades(Date date, int num) {
		while (num != 0)
		{
			date = IncreaseDateByOneDecade(date);
			num--;
		}
		return date;
	}

	Date IncreaseDateByXDecades(int num) {
		return IncreaseDateByXDecades(*this, num);
	}

	static Date IncreaseDateByXDecadesFaster(Date date, int num) {
		date.year += (num * 10);
		return date;
	}

	Date IncreaseDateByXDecadesFaster(int num) {
		return IncreaseDateByXDecadesFaster(*this, num);
	}

	static Date IncreaseDateByOneCentury(Date date) {
		return IncreaseDateByXDecades(date, 10);
	}

	Date IncreaseDateByOneCentury() {
		return IncreaseDateByOneCentury(*this);
	}

	static Date IncreaseDateByOneMillennium(Date date) {
		date.year += 1000;
		return date;
	}

	Date IncreaseDateByOneMillennium() {
		return IncreaseDateByOneMillennium(*this);
	}

	static void PrintDate(Date date) {
		cout << date.day << "/" << date.month << "/" << date.year << endl;
	}

	void PrintDate() {
		PrintDate(*this);
	}

	static Date DecreaseDateByOneDay(Date date) {
		if (date.day == 1) {
			date.day = DaysInMonth(date.month, date.year);

			if (date.month == 1) {
				date.month = 12;
				date.year--;
			}
			else {
				date.month--;
			}
		}
		else
		{
			date.day--;
		}
		return date;
	}

	Date DecreaseDateByOneDay() {
		return DecreaseDateByOneDay(*this);
	}

	static Date DecreaseDateByXDays(Date date, int num) {
		while (num != 0)
		{
			date = DecreaseDateByOneDay(date);
			num--;
		}
		return date;
	}

	Date DecreaseDateByXDays(int num) {
		return DecreaseDateByXDays(*this, num);
	}

	static Date DecreaseDateByOneWeek(Date date) {
		return DecreaseDateByXDays(date, 7);
	}

	Date DecreaseDateByOneWeek() {
		return DecreaseDateByOneWeek(*this);
	}

	static Date DecreaseDateByXWeeks(Date date, int num) {
		while (num != 0)
		{
			date = DecreaseDateByOneWeek(date);
			num--;
		}
		return date;
	}

	Date DecreaseDateByXWeeks(int num) {
		return DecreaseDateByXWeeks(*this, num);
	}

	static Date DecreaseDateByOneMonth(Date date) {
		return DecreaseDateByXDays(date, DaysInMonth(date.month, date.year));
	}

	Date DecreaseDateByOneMonth() {
		return DecreaseDateByOneMonth(*this);
	}

	static Date DecreaseDateByXMonths(Date date, int num) {
		while (num != 0)
		{
			date = DecreaseDateByOneMonth(date);
			num--;
		}
		return date;
	}

	Date DecreaseDateByXMonths(int num) {
		return DecreaseDateByXMonths(*this, num);
	}

	static Date DecreaseDateByOneYear(Date date) {
		return DecreaseDateByXMonths(date, 12);
	}

	Date DecreaseDateByOneYear() {
		return DecreaseDateByOneYear(*this);
	}

	static Date DecreaseDateByXYears(Date date, int num) {
		while (num != 0)
		{
			date = DecreaseDateByOneYear(date);
			num--;
		}
		return date;
	}

	Date DecreaseDateByXYears(int num) {
		return DecreaseDateByXYears(*this, num);
	}

	static Date DecreaseDateByXYearsFaster(Date date, int num) {
		date.year -= num;
		return date;
	}

	Date DecreaseDateByXYearsFaster(int num) {
		return DecreaseDateByXYearsFaster(*this, num);
	}

	static Date DecreaseDateByOneDecade(Date date) {
		return DecreaseDateByXYears(date, 10);
	}

	Date DecreaseDateByOneDecade() {
		return DecreaseDateByOneDecade(*this);
	}

	static Date DecreaseDateByXDecades(Date date, int num) {
		while (num != 0)
		{
			date = DecreaseDateByOneDecade(date);
			num--;
		}
		return date;
	}

	Date DecreaseDateByXDecades(int num) {
		return DecreaseDateByXDecades(*this, num);
	}

	static Date DecreaseDateByXDecadesFaster(Date date, int num) {
		date.year -= (num * 10);
		return date;
	}

	Date DecreaseDateByXDecadesFaster(int num) {
		return DecreaseDateByXDecadesFaster(*this, num);
	}

	static Date DecreaseDateByOneCentury(Date date) {
		return DecreaseDateByXDecades(date, 10);
	}

	Date DecreaseDateByOneCentury() {
		return DecreaseDateByOneCentury(*this);
	}

	static Date DecreaseDateByOneMillennium(Date date) {
		date.year -= 1000;
		return date;
	}

	Date DecreaseDateByOneMillennium() {
		return DecreaseDateByOneMillennium(*this);
	}

	static int DayOrderInWeek(int day, int month, int year) {
		int a = (14 - month) / 12;
		int y = year - a;
		int m = month + (12 * a) - 2;

		int d = (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

		return d;
	}

	static int DayOrderInWeek(Date date) {
		int a = (14 - date.month) / 12;
		int y = date.year - a;
		int m = date.month + (12 * a) - 2;

		int d = (date.day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

		return d;
	}

	int DayOrderInWeek() {
		return DayOrderInWeek(*this);
	}

	static bool IsEndOfWeek(int dayOrder) {
		return (dayOrder == 6);
	}

	bool IsEndOfWeek() {
		return IsEndOfWeek(DayOrderInWeek());
	}

	static bool IsWeekend(int dayOrder) {
		return (dayOrder == 5 || dayOrder == 6);
	}

	bool IsWeekend() {
		return IsWeekend(DayOrderInWeek());
	}

	static bool IsBusinessDay(int dayOrder) {
		return !IsWeekend(dayOrder);
	}

	bool IsBusinessDay() {
		return IsBusinessDay(DayOrderInWeek());
	}

	static int DaysUntilEndOfWeek(int dayOrder) {
		return (7 - (dayOrder + 1));
	}

	int DaysUntilEndOfWeek() {
		return DaysUntilEndOfWeek(DayOrderInWeek());
	}

	static int DaysUntilEndOfMonth(Date date) {
		return DaysInMonth(date.month, date.year) - date.day;
	}

	int DaysUntilEndOfMonth() {
		return DaysUntilEndOfMonth(*this);
	}

	static int DaysUntilEndOfYear(Date date) {
		int sum = DaysUntilEndOfMonth(date);
		date.month++;

		while (date.month <= 12)
		{
			sum += DaysInMonth(date.month, date.year);
			date.month++;
		}
		return sum;
	}

	int DaysUntilEndOfYear() {
		return DaysUntilEndOfYear(*this);
	}

	static int ActualVacationDays(Date start, Date end) {
		int BusinessDaysSum = 0;
		while (!IsDatesEquals(start, end))
		{
			if (IsBusinessDay(DayOrderInWeek(start)))	BusinessDaysSum++;
			start = IncreaseDateByOneDay(start);
		}
		return BusinessDaysSum;
	}

	static Date ReturnDate(Date start, short vacationDays) {
		short WeekendCounter = 0;

		for (short i = 1; i <= vacationDays + WeekendCounter; i++)
		{
			if (IsWeekend(DayOrderInWeek(start))) WeekendCounter++;
			start = IncreaseDateByOneDay(start);
		}

		while (IsWeekend(DayOrderInWeek(start))) start = IncreaseDateByOneDay(start);

		return start;
	}

	Date ReturnDate(short vacationDays) {
		return ReturnDate(*this, vacationDays);
	}

	static bool IsDate1AfterDate2(Date date1, Date date2) {
		return !IsDate1BeforeDate2(date1, date2) && !IsDatesEquals(date1, date2);
	}

	static short CompareDates(Date date1, Date date2) {
		if (IsDate1BeforeDate2(date1, date2)) return -1;
		if (IsDatesEquals(date1, date2)) return 0;
		return 1;
	}

	static bool IsDateValid(Date date) {
		return !((date.day < 1 || date.day > DaysInMonth(date.month, date.year)) || (date.month < 1 || date.month > 12) || (date.year < 1));
	}

	bool IsDateValid() {
		return IsDateValid(*this);
	}

	static Date StringToDate(string date_str) {
		Date date;
		vector <string> dateSeparated = splitToVector(date_str, "/");

		date.day = stoi(dateSeparated.at(0));
		date.month = stoi(dateSeparated.at(1));
		date.year = stoi(dateSeparated.at(2));

		return date;
	}

	static string FormatDate(Date date, string format = "dd/mm/yyyy") {
		string temp;

		temp = ReplaceWordInString("dd", to_string(date.day), format);
		temp = ReplaceWordInString("mm", to_string(date.month), temp);
		temp = ReplaceWordInString("yyyy", to_string(date.year), temp);

		return temp;
	}

	string FormatDate(string format = "dd/mm/yyyy") {
		return FormatDate(*this, format);
	}

};