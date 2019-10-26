/*
问题 B: 数制转换

题目描述

求任意两个不同进制非负整数的转换（2进制～16进制），所给整数在long所能表达的范围之内。
不同进制的表示符号为（0，1，...，9，a，b，...，f）或者（0，1，...，9，A，B，...，F）。
输入

输入只有一行，包含三个整数a，n，b。a表示其后的n 是a进制整数，b表示欲将a进制整数n转换成b进制整数。a，b是十进制整数，2 =< a，b <= 16。
输出

可能有多组测试数据，对于每组数据，输出包含一行，该行有一个整数为转换后的b进制数。输出时字母符号全部用大写表示，即（0，1，...，9，A，B，...，F）。
样例输入

4 123 10

样例输出

27

*/
#include<bits/stdc++.h>
using namespace std;

map<int,char> myi2c;
map<char,int> myc2i;

int main() {
	//var
	int a, b;
	string n;
	for(int i = 0; i < 10; i++) { 
		myi2c[i] = i + '0';
		myc2i[i + '0'] = i;
	}
	myi2c[10] = 'A'; myc2i['A'] = 10; myc2i['a'] = 10;
	myi2c[11] = 'B'; myc2i['B'] = 11; myc2i['b'] = 11;
	myi2c[12] = 'C'; myc2i['C'] = 12; myc2i['c'] = 12;
	myi2c[13] = 'D'; myc2i['D'] = 13; myc2i['d'] = 13;
	myi2c[14] = 'E'; myc2i['E'] = 14; myc2i['e'] = 14;
	myi2c[15] = 'F'; myc2i['F'] = 15; myc2i['f'] = 15;
	//input
	while(true){
		if(cin.eof()) break;
		string s;
		getline(cin, s);
		int pos1 = s.find(" ", 0);
		int pos2 = s.find(" ", pos1 + 1);
		a = stoi(s.substr(0, pos1));
		b = stoi(s.substr(pos2+1, s.size()-pos2-1));
		n = s.substr(pos1+1, pos2-pos1-1);
		//a -> 10
		int sum = 0; 
		for(int i = 0; i < n.size(); i++) {
			sum = a*sum + myc2i[n[i]];
		}
		//10 -> b
		s = "";
		if(sum == 0) s = "0"; //!!! conner case !!!
		while(sum != 0) {
			s += myi2c[sum % b];
			sum /= b;
		}
		//output
		for(int i = s.size() - 1; i >= 0; i--) {
			printf("%c", s[i]);
		}
		printf("\n");
	} 
	return 0;
}
