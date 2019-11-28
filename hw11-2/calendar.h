#include <iostream>
using namespace std;
class Date{
	public:
		Date();
		Date(int year,int month,int day);
		void NextDay(int n);
		void SetDate(int year,int month, int day);
		int GetYear() const;
		int GetMonth() const;		
		int GetDay() const;
		bool IsValid() const;
	private:
		static int GetDaysInYear(int year);

		static int ComputeDaysFromYearStart(int year,int month, int day);
		int year_,month_,day_;
		int yearcheck;
		bool validity;
};

ostream& operator<< (ostream& os,const Date& c);

istream& operator>>(istream& is,Date& c);

