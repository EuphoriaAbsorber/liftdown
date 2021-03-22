#pragma once
#include <vector>
using namespace std;
//#include "Classlift.cpp"
class lift {
public:
	int m_cap;
	long long m_time;
	int m_floor;

public:
	lift();
	//lift(const lift& rv);
	//~lift();
	//void init();
	//int copy(const lift& rv);
	//int copy(const int cap, const long long time);
	int is_lift_free(int time);
	friend int findlift(lift* lifts, int lift_count, int floor, long long time);
	friend void time_update(lift* lifts, int lift_count, long long time);
	void gotofloor(int n);
	long long get_time();
};
