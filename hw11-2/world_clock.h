#include <iostream>
using namespace std;

class WorldClock{
	public:
		void Tick(int seconds);
		void SetTime(int hour,int minute,int second);
		void SetInvalid(int hour, int minute, int second);
		bool IfValid() const;
		int ReturnTime() const;
		int ihour,iminute,isecond;
		
	private:
		int timezone;
		bool validity;
};

ostream& operator<< (ostream& os,const WorldClock& c);

istream& operator>>(istream& is,WorldClock& c);
