#include "world_clock.h"
#include <string.h>
#include <stdlib.h>

using namespace std;

void WorldClock::Tick(int seconds){
	timezone += seconds;
	if(timezone<0)
		timezone = 24*3600+timezone;
	if(timezone>=24*3600)
		timezone -= 24*3600;
}
void WorldClock::SetTime(int hour,int minute,int second){
	validity = true;
	timezone = hour*3600 + minute*60 + second;
}
void WorldClock::SetInvalid(int hour,int minute,int second){
	validity = false;
	ihour= hour;
	iminute = minute;
	isecond = second;
}
bool WorldClock::IfValid() const{
	return validity;
}
int WorldClock::ReturnTime() const{
	return timezone;
}

ostream& operator<< (ostream& os,const WorldClock& c){
	if(c.IfValid() == false){
		os << "Invalid time: " << c.ihour << ":" << c.iminute << ":" << c.isecond;
		return os;
	}
	int second = c.ReturnTime();
	int hour = second/3600;
	second -= hour*3600;
	int minute = second/60;
	second -= minute*60;
	os << hour << ":" << minute << ":" << second;
	return os;
}

istream& operator>>(istream& is,WorldClock& c){
	char str[50];
	int hour,minute,second;
	is >> str;
	char* ptr = strtok(str,":");
	hour = atoi(ptr);
	ptr = strtok(NULL,":");
	minute = atoi(ptr);
	ptr = strtok(NULL,":");
	second = atoi(ptr);
	if(hour>23 || minute>59 || second>59){	
		c.SetInvalid(hour,minute,second);
		return is;
	}
	c.SetTime(hour,minute,second);
	return is;
}
