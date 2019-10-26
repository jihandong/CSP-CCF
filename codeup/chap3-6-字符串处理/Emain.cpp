/*
字符串去特定字符

题目描述

输入字符串s和字符c，要求去掉s中所有的c字符，并输出结果。
输入

测试数据有多组，每组输入字符串s和字符c。
输出

对于每组输入,输出去除c字符后的结果。
样例输入

goaod
a

样例输出

good
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
	//var
	string s1, s2;
	//input
	while(true) {
		if(cin.eof()) break;
		getline(cin, s1);
		getline(cin, s2);
		for(int i = 0; i < s1.size();) {
			if(s1[i] == s2[0]) {
				s1.erase(s1.begin() + i);
			} else {
				i++;
			}
		}
		//output
		printf("%s\n", s1.c_str());
	}
	return 0;
}

