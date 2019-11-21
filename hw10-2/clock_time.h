#ifndef CLOCK_TIME_H
#define CLOCK_TIME_H

#define SECONDS_PER_MINUTE 60
#define MINUTES_PER_HOUR 60
#define HOURS_PER_DAY 24

class ClockTime{
public:
	ClockTime();
	
	ClockTime(int,int,int,int);
	~ClockTime(){
		hour_ = minute_ = second_ = secondsPerTick_ = startTime_ = 0;
	};
	int const hour() const{return hour_;}
	int const minute() const{return minute_;}
	int const second() const{return second_;}
	int const secondsPerTick() const{return secondsPerTick_;}
	
	unsigned int startTime() const{return startTime_;}
	unsigned int deltaTime() const{return deltaTime_;}

	void setTime(ClockTime const& initialTime){
		hour_ = initialTime.hour_;
		minute_ = initialTime.minute_;
		second_ = initialTime.second_;
		secondsPerTick_ = initialTime.secondsPerTick_;
		deltaTime_ = 0;
	}
	void setTime(int hour, int minute, int second, int secondsPerTick){
		hour_ = hour;
		minute_ =minute;
		second_ = second;
		secondsPerTick_ =secondsPerTick;
		deltaTime_ = 0;
	}
	void reset();
	void increment();
	void display() const;
private:
	int hour_;
	int minute_;
	int second_;
	int secondsPerTick_;
	unsigned int startTime_;
	unsigned int deltaTime_;
	void recordStartTime();
};

#endif
