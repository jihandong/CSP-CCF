#include<bits/stdc++.h>
using namespace std;

int months[13][2] = {
	{0, 0}, 
	{31, 31}, //1
	{28, 29}, //2
	{31, 31}, //3
	{30, 30}, //4
	{31, 31}, //5
	{30, 30}, //6
	{31, 31}, //7
	{31, 31}, //8
	{30, 30}, //9
	{31, 31}, //10
	{30, 30}, //11
	{31, 31} //12
};

int isleap(int y) {
	if((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
		return 1;
	else
		return 0;
}

int main() {
	int y1, m1, d1, y2, m2, d2, data1, data2;
	//input
	while((scanf("%d%d", &data1, &data2)) != EOF) {
		if (data1 > data2) {
			int tmp = data1;
			data1 = data2;
			data2 = tmp;
		}
		y1 = data1 / 10000; m1 = (data1 % 10000) / 100; d1 = data1 % 100;
		y2 = data2 / 10000; m2 = (data2 % 10000) / 100; d2 = data2 % 100;
		//count days
		int cnt = 1;
		while(y1 < y2 || m1 < m2 || d1 < d2) {
			
			d1++; cnt++;
			//next month
			if(d1 > months[m1][isleap(y1)]) {
				m1++;
				d1 = 1;
				//fast month
				while(y1 == y2 && m1 < m2) {
					cnt += months[m1][isleap(y1)];
					m1++;
				}
				
			}
			//next year
			if(m1 > 12) {
				y1++;
				m1 = 1;
				//fast year
				while(y1 < y2) {
					cnt += isleap(y1)? 366 : 365; 
					y1++;
				}
			}
		}
		//output
		printf("%d\n", cnt);
	}
	return 0;
} 
