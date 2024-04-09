#pragma once
#pragma warning(disable : 4996)
#include "Date.h"
using namespace std;

class Period
{
private:

public:
	Date startDate;
	Date endDate;


	Period(Date startDate, Date endDate) {
		this->startDate = startDate;
		this->endDate = endDate;
	}


	void PrintPeriod() {
		cout << "Period start : "; Date::PrintDate(startDate);
		cout << "Period end : "; Date::PrintDate(endDate);
	}

	static bool IsOverlapped(Period per1, Period per2) {
		return !(Date::IsDate1AfterDate2(per2.startDate, per1.endDate) || Date::IsDate1BeforeDate2(per2.endDate, per1.startDate));
	}

	bool IsOverlapped(Period per) {
		return IsOverlapped(*this, per);
	}

	static int LengthInDays(Period per, bool IncludeEndDay = false) {
		return Date::DateDifference(per.startDate, per.endDate, IncludeEndDay);
	}

	int LengthInDays(bool IncludeEndDay = false) {
		return LengthInDays(*this, IncludeEndDay);
	}

	static bool IsDateWithinPeriod(Date date, Period per) {
		if (Date::IsDate1AfterDate2(per.startDate, per.endDate)) {
			Date::SwapTwoDates(per.startDate, per.endDate);
		}

		return Date::IsDate1AfterDate2(date, per.startDate) && Date::IsDate1BeforeDate2(date, per.endDate);
	}

	bool IsDateWithinPeriod(Date date) {
		return IsDateWithinPeriod(date, *this);
	}

	static int CountOverlap(Period per1, Period per2) {
		int OverlappedDays = 0;
		int per1Length = LengthInDays(per1);
		int per2Length = LengthInDays(per2);

		if (!IsOverlapped(per1, per2)) return 0; // Catch The 0 Case.

		if (per1Length < per2Length)
		{
			while (!Date::IsDatesEquals(per1.startDate, per1.endDate))
			{
				if (IsDateWithinPeriod(per1.startDate, per2)) {
					OverlappedDays += 1;
				}
				per1.startDate = Date::IncreaseDateByOneDay(per1.startDate);
			}
		}
		else
		{
			while (!Date::IsDatesEquals(per2.startDate, per2.endDate))
			{
				if (IsDateWithinPeriod(per2.startDate, per1)) {
					OverlappedDays += 1;
				}
				per2.startDate = Date::IncreaseDateByOneDay(per2.startDate);
			}
		}
		return OverlappedDays;
	}

	int CountOverlap(Period per) {
		return CountOverlap(*this, per);
	}
};