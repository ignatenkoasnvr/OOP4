#pragma once
#include <string>
#include <iostream>
using namespace std;
namespace my
{
	class Time {
		int hour;
		int min;
		int sec;
	public:
		Time() {
			hour = 0;
			min = 0;
			sec = 0;
		}
		Time(const string& time);
		Time& operator = (const Time& original) {
			hour = original.hour;
			min = original.min;
			sec = original.sec;
			return *this;
		}

		friend Time operator +(const Time& time1, const Time& time2);
		friend Time operator -(const Time& time1, const Time& time2);
		//	friend Time operator +=(Time& time1, const Time& time2);
		//	friend Time operator -=(Time& time1, const Time& time2);
		friend bool operator == (const Time& time1, const Time& time2);
		friend bool operator != (const Time& time1, const Time& time2);

		void print() const {
			if (hour < 10)
				cout << "0";
			cout << hour << ":";
			if (min < 10)
				cout << "0";
			cout << min << ":";
			if (sec < 10)
				cout << "0";
			cout << sec << endl;
		}

	};
}