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
	int y, n, m, d;
	while((scanf("%d%d", &y, &n)) > 0) {
		m = 1;
		//fast add month
		while(n > months[m][isleap(y)]) {
			n -= months[m][isleap(y)];
			m++;
		}
		//rest days
		d = n;
		//output
		printf("%04d-%02d-%02d\n", y, m, d);
	} 
	return 0;
} 
