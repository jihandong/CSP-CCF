#include<bits/stdc++.h>
using namespace std;
int M[13][2] = {
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
map<string,int> months;
string weeks[7] = {
	"Sunday",
	"Monday",
	"Tuesday",
	"Wednesday",
	"Thursday",
	"Friday",
	"Saturday"
};

bool isearly(int y1, int m1, int d1, int y2, int m2, int d2) {
	if(y1 < y2) {
		return true;
	} else if(y1 > y2) {
		return false;
	} else if(m1 < m2) {
		return true;
	} else if(m1 > m2) {
		return false;
	} else if(d1 < d2) {
		return true;
	} else {
		return false;
	}
}

int isleap(int y) {
	if((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
		return 1;
	else 
		return 0;
}

int main() {
	//set 
	bool inputGreat;
	int y1, m1, d1, y2, m2, d2, w;
	months["January"] = 1;
	months["February"] = 2;
	months["March"] = 3;
	months["April"] = 4;
	months["May"] = 5;
	months["June"] = 6;
	months["July"] = 7;
	months["August"] = 8;
	months["September"] = 9;
	months["October"] = 10;
	months["November"] = 11;
	months["December"] = 12;
	while(true) {
		//initial
		inputGreat = true; 
		y1 = 2019, m1 = 10, d1 = 20, w = 0;
		//input
		if(cin.eof()) break;
		string str;
		getline(cin, str);
		int blank1 = str.find(" ", 0);
		int blank2 = str.find(" ", blank1+1);
		d2 = stoi(str.substr(0, blank1));
		m2 = months[str.substr(blank1+1, blank2-blank1-1)];
		y2 = stoi(str.substr(blank2+1, str.size()-blank2-1));
		//compare
		if(!isearly(y1, m1, d1, y2, m2, d2)) {
			int tmp;
			tmp = y1, y1 = y2, y2 = tmp;
			tmp = m1, m1 = m2, m2 = tmp;
			tmp = d1, d1 = d2, d2 = tmp;
			inputGreat = false;
		}
		//count
		int cnt = 0;
		while(y1 < y2 || m1 < m2 || d1 < d2) {
			d1++; cnt++;
			//next month
			if(d1 > M[m1][isleap(y1)]) {
				m1++;
				d1 = 1;
				//fast
				while(y1 == y2 && m1 < m2) {
					cnt += M[m1][isleap(y1)];
					m1++;
				}
			}
			//next year
			if(m1 > 12) {
				y1++;
				m1 = 1;
				//fast
				while(y1 < y2) {
					cnt += isleap(y1)? 366 : 365;
					y1++;
				}
			}
		}
		//output
		if(inputGreat) {
			w = (w + cnt) % 7;
		} else {
			w = (w + (cnt/7 + 1)*7 - cnt) % 7;
		}
		printf("%s\n", weeks[w].c_str());
	}
	
	return 0;
} 
