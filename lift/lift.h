#pragma once
//#include "Classlift.cpp"
class lift {
protected:
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
	int is_lift_free();
	int findlift(lift &a, int lift_count);
	void gotofloor(int n);
	long long get_time();
};
