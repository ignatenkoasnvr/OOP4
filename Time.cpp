#include "Time.h"
#include <iostream>
#include <string>
using namespace std;
using namespace my;
Time::Time(const string& str)
{
	hour = (stoi(str.substr(0, 2))) % 24;
	min = (stoi(str.substr(3, 2))) % 60;
	sec = (stoi(str.substr(6, 2))) % 60;
}
Time operator +(const Time& time1, const Time& time2) {
	int tmp_sec = (time1.sec + time2.sec) % 60;
	int tmp_min = (time1.min + time2.min) % 60 + ((time1.sec + time2.sec) / 60);
	int tmp_hour = (time1.hour + time2.hour) % 24 + (time1.min + time2.min) / 60;
	
	string tmp;
	if (tmp_hour < 10)
		tmp = "0";
	tmp += to_string(tmp_hour) + ":";
	if (tmp_min < 10)
		tmp += "0";
	tmp += to_string(tmp_min) + ":";
	if (tmp_sec<10)
		tmp += "0";
	tmp += to_string(tmp_sec);
	return Time(tmp);
}
Time operator -(const Time& time1, const Time& time2) {
	int tmp_hour, tmp_min, tmp_sec;
	if (time1.hour >= time2.hour)
		tmp_hour = (time1.hour - time2.hour) % 24;
	else
		tmp_hour = 24 + (time1.hour - time2.hour) % 24;

	if (time1.min >= time2.min)
		tmp_min = (time1.min - time2.min) % 60;
	else {
		tmp_min = 60 + (time1.min - time2.min) % 60;
		tmp_hour = tmp_hour - (time1.min - time2.min) / 60;
	}

	if (time1.sec >= time2.sec)
		tmp_sec = (time1.sec - time2.sec) % 60;
	else {
		tmp_sec = 60 + ((time1.sec - time2.sec) % 60);
		tmp_min = tmp_min - (time1.sec - time2.sec) / 60;
	}
	string tmp = to_string(tmp_hour) + ":" + to_string(tmp_min) + ":" + to_string(tmp_sec);
	return Time(tmp);
}


bool operator == (const Time& time1, const Time& time2) {
	return time1.hour == time2.hour && time1.min == time2.min && time1.sec == time2.sec;
}

bool operator != (const Time& time1, const Time& time2) {
	return time1.hour != time2.hour || time1.min != time2.min || time1.sec != time2.sec;
}




