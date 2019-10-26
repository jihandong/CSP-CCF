/*
数组逆置

题目描述

输入一个字符串，长度小于等于200，然后将数组逆置输出。
输入

测试数据有多组，每组输入一个字符串。
输出

对于每组输入,请输出逆置后的结果。
样例输入

tianqin

样例输出

niqnait

*/
#include<bits/stdc++.h>
using namespace std;

int main() {
	//var
	string s;
	//input
	while(true) {
		if(cin.eof()) break;
		getline(cin, s);
		for(int i = s.size()-1; i >= 0; i--) {
			printf("%c", s[i]);
		}	printf("\n");
	}
	return 0;
}

