#include <iostream>
#include <stdio.h>
#include <cmath>
#include <math.h>
#define ISYEAR(x) (x%4 == 0 && x%100 != 0) || x%400 == 0 ? 1:0
using namespace std;

int dayOfMonth[13][2]={
	0,0,
	31,31,
	28,29,
	31,31,
	30,30,
	31,31,
	30,30,
	31,31,
	31,31,
	30,30,
	31,31,
	30,30,
	31,31
};
struct Date{
	int Day, Month, Year;
	void nextDay(){
		Day++;
		if(Day > dayOfMonth[Month][ISYEAR(Year)]){
			Day = 1;
			Month++;
			if(Month > 12){
				Month = 1;
				Year++;
			}
		}
	}
};

int buf[5000][13][32];

int main(int argc, char const *argv[])
{
	/* code */
	int cnt = 0;
	Date tmp;
	tmp.Day = 1;
	tmp.Month = 1;
	tmp.Year = 0;
	while(tmp.Year != 5000){
		buf[tmp.Year][tmp.Month][tmp.Day] = cnt;
		tmp.nextDay();
		cnt++;
	}
	int d1, m1, y1;
	int d2, m2, y2;
	while(scanf("%4d%2d%2d", &y1, &m1, &d1) != EOF){
		scanf("%4d%2d%2d", &y2, &m2, &d2);
		printf("%d\n", int(abs(buf[y1][m1][d1] - buf[y2][m2][d2]) + 1));
	}
	return 0;
}