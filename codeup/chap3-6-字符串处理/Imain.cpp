/*
【字符串】回文串

题目描述

读入一串字符，判断是否是回文串。“回文串”是一个正读和反读都一样的字符串，比如“level”或者“noon”等等就是回文串。
输入

一行字符串，长度不超过255。
输出

如果是回文串，输出“YES”，否则输出“NO”。
样例输入

12321

样例输出

YES

*/
#include<bits/stdc++.h>
using namespace std;

int main() {
	//var
	while(true) {
		if(cin.eof()) break;
		string s;
		getline(cin, s);
		bool flag = true;
		for(int i = 0; i < s.size()/2; i++) {
			if(s[i] != s[s.size()-1-i]) {
				flag = false;
				break;
			}
		}
		//output
		if(flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
