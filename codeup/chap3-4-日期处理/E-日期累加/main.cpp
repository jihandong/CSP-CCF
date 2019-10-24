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
	{31, 31}, //12
};

int isleap(int y) {
	if((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
		return 1;
	else 
		return 0;
}

int main() {
	//var
	int M;
	scanf("%d", &M);
	for(int i = 0; i < M; i++) {
		int y, m, d, cnt;
		scanf("%d%d%d%d", &y, &m, &d, &cnt);
		while(cnt > 0) {
			cnt--;
			d++;
			//add month
			if(d > months[m][isleap(y)]) {
				d = 1;
				m++;
				//fast month
				while(cnt > months[m][isleap(y)] && m <= 12) {
					cnt -= months[m][isleap(y)];
					m++;
				}
			}
			//add year
			if(m > 12) {
				m = 1;
				y++;
				//fast year
				while(cnt > (isleap(y)? 366 : 365)) {
					cnt -= (isleap(y)? 366 : 365);
					y++;
				}
			}
		}
		//output
		printf("%04d-%02d-%02d\n", y, m, d);
	}
	return 0; 
}
