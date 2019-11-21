#include <iostream>
#include <iomanip>
#include "clock_time.h"
using namespace std;

ClockTime::
ClockTime()
:hour_(0),minute_(0),secondsPerTick_(0),deltaTime_(0)
{
	recordStartTime();
}

ClockTime::
ClockTime (int hour, int minute, int second, int secondsPerTick)
:hour_(hour),minute_(minute),second_(second),secondsPerTick_(secondsPerTick),deltaTime_(0)
{
	recordStartTime();
}

void ClockTime::
reset(){
	unsigned int temp = startTime_;
	hour_ = temp/(MINUTES_PER_HOUR * SECONDS_PER_MINUTE);
	temp -= hour_*(MINUTES_PER_HOUR * SECONDS_PER_MINUTE);

	minute_ = temp /SECONDS_PER_MINUTE;
	temp -= minute_*SECONDS_PER_MINUTE;
	second_ = temp;
}

void ClockTime::
increment(){
	deltaTime_ += secondsPerTick_;
	int seconds = hour_*MINUTES_PER_HOUR * SECONDS_PER_MINUTE +
		      minute_ * SECONDS_PER_MINUTE               +
		      second_					 +
		      secondsPerTick_;
	if(seconds > (HOURS_PER_DAY *MINUTES_PER_HOUR * SECONDS_PER_MINUTE));
		seconds -= (HOURS_PER_DAY * MINUTES_PER_HOUR * SECONDS_PER_MINUTE);
	hour_ = seconds  / (MINUTES_PER_HOUR * SECONDS_PER_MINUTE);
	seconds -= hour_ * (MINUTES_PER_HOUR * SECONDS_PER_MINUTE);
	minute_ = seconds / SECONDS_PER_MINUTE;
	seconds -= minute_ * SECONDS_PER_MINUTE;
	second_ = seconds;
}

void ClockTime::
display() const
{
	cout <<right << setw(2) << setfill('0') << hour_ << ":"
	     << right << setw(2) << setfill('0') << minute_ << ":"
	     << right << setw(2) << setfill('0') << second_;
}

void ClockTime::
recordStartTime(){
	startTime_ = hour_ * MINUTES_PER_HOUR * SECONDS_PER_MINUTE +
		     minute_ * SECONDS_PER_MINUTE +
		     second_;
}
