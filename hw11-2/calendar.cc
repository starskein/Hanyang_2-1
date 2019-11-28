#include "calendar.h"
#include <string.h>
#include <stdlib.h>


Date::Date(){}
Date::Date(int year,int month,int day){
	year_ = year;
	month_ = month;
	day_ = day;
	yearcheck = 0;
	if(year_ % 4 == 0){
		yearcheck = 1;
		if(year_ % 100 == 0){
			yearcheck = 0;
			if(year_ % 400 == 0) yearcheck = 1;
		}
	}
}
int Date::GetDaysInYear(int year){
	int yearcheck_;
	if(year % 4 == 0){
                yearcheck_ = 1;
                if(year % 100 == 0){
                        yearcheck_ = 0;
                        if(year % 400 == 0) yearcheck_ = 1;
                }
        }
	return 365+yearcheck_;
}

int Date::ComputeDaysFromYearStart(int year,int month, int day){
	int yearcheck_=0;
	if(year % 4 == 0){
                yearcheck_ = 1;
                if(year % 100 == 0){
                        yearcheck_ = 0;
                        if(year % 400 == 0) yearcheck_ = 1;
                }
        }

	int totalday = day;
        if(month == 2) totalday+=31;
        else if(month == 3) totalday += 59+yearcheck_;
        else if(month == 4) totalday += 90+yearcheck_;
        else if(month == 5) totalday += 120+yearcheck_;
        else if(month == 6) totalday += 151+yearcheck_;
        else if(month == 7) totalday += 181+yearcheck_;
        else if(month == 8) totalday += 212+yearcheck_;
        else if(month == 9) totalday += 243+yearcheck_;
        else if(month == 10) totalday += 273+yearcheck_;
        else if(month == 11) totalday += 304+yearcheck_;
        else if(month == 12) totalday += 334+yearcheck_;
	return totalday;
}

void Date::NextDay(int n){
	int totalday = 0;
	totalday = ComputeDaysFromYearStart(year_,month_,day_);
//	cout << totalday <<endl;
	totalday += n;
//	cout << totalday << endl;
	if (totalday <= 0){
		year_--;
		if(year_ % 4 == 0){
                	yearcheck = 1;
                	if(year_ % 100 == 0){
                        	yearcheck = 0;
                        	if(year_ % 400 == 0) yearcheck = 1;
                	}
       		}
		totalday = GetDaysInYear(year_) -totalday;
	}
	if(totalday > 365+yearcheck){
		year_++;
                totalday = totalday - (365+yearcheck);
		if(year_ % 4 == 0){
                        yearcheck = 1;
                        if(year_ % 100 == 0){
                                yearcheck = 0;
                                if(year_ % 400 == 0) yearcheck = 1;
                        }
                }
        }

	if(totalday <= 31 ){ 	
		month_ = 1;
		day_ = totalday;
	}
	else if(totalday <=59+yearcheck){ 
		month_ = 2;
		day_ = totalday - 31;
	}
	else if(totalday <=90+yearcheck){ 
		month_ = 3;
		day_ = totalday -(59+yearcheck);
	}
	else if(totalday <=120+yearcheck){ 
		month_ = 4;
		day_ = totalday - (90+yearcheck);
	}
	else if(totalday <=151+yearcheck){
		month_ = 5;
		day_ = totalday - (120+yearcheck);
	}
	else if(totalday <=181+yearcheck){
		month_ = 6;
		day_ = totalday -(151+yearcheck);
	}
	else if(totalday <=212+yearcheck){ 
		month_ = 7;
		day_ = totalday - (181+yearcheck);
	}
	else if(totalday <=243+yearcheck){ 
		month_ = 8;
		day_ = totalday - (212+yearcheck);
	}
	else if(totalday <=274+yearcheck){ 
		month_ = 9;
		day_ = totalday - (243+yearcheck);
	}
	else if(totalday <=303+yearcheck){ 
		month_ = 10;
		day_ = totalday - (274+yearcheck);
	}
	else if(totalday <=334+yearcheck){
		month_ = 11;
		day_ = totalday - (303+yearcheck);
	}
	else{
		month_=12;
		day_ = totalday - (334+yearcheck);
	}
	validity = true;
        if(month_>12) validity = false;
        if(day_ >31) validity = false;
        if(month_ ==2 && day_ > 28+yearcheck) validity = false;
        if(month_ == 4 || month_ == 6 || month_ == 9 || month_ == 11){
                if(day_ > 30) validity = false;
        }

}
void Date::SetDate(int year,int month, int day){
	year_ = year;
        month_ = month;
        day_ = day;
	yearcheck = 0;
        if(year_ % 4 == 0){
                yearcheck = 1;
                if(year_ % 100 == 0){
                        yearcheck = 0;
                        if(year_ % 400 == 0) yearcheck = 1;
                }
        }
	validity = true;
	if(month_>12) validity = false;
	if(day_ >31) validity = false;
	if(month_ ==2 && day_ > 28+yearcheck) validity = false;
	if(month_ == 4 || month_ == 6 || month_ == 9 || month_ == 11){
		if(day_ > 30) validity = false;
	}
}
bool Date::IsValid() const{
	return validity;
}
int Date::GetYear() const{
	return year_;
}
int Date::GetMonth() const{
        return month_;
}
int Date::GetDay() const{
	return day_;
}

ostream& operator<<(ostream& os, const Date& c){
	if(c.IsValid() == false){
		os << "Invalid date: " << c.GetYear() << "." << c.GetMonth() << "." << c.GetDay();
		return os;
	}
	os << c.GetYear() << "." << c.GetMonth() << "." << c.GetDay();
	return os;
}

istream& operator>>(istream& is, Date& c){
	char str[50];
	int year,month,day;
	is >> str;
	char* ptr = strtok(str,".");
	year = atoi(ptr);
	ptr = strtok(NULL,".");
	month = atoi(ptr);
	ptr = strtok(NULL,".");
	day = atoi(ptr);
	c.SetDate(year,month,day);
	return is;
}
	
	

	
