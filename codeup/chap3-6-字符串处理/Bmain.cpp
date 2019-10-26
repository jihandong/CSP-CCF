/*
首字母大写

题目描述

对一个字符串中的所有单词，如果单词的首字母不是大写字母，则把单词的首字母变成大写字母。
在字符串中，单词之间通过空白符分隔，空白符包括：空格(' ')、制表符('\t')、回车符('\r')、换行符('\n')。
输入

输入一行：待处理的字符串（长度小于100）。
输出

可能有多组测试数据，对于每组数据，
输出一行：转换后的字符串。
样例输入

if so, you already have a google account. you can sign in on the right.

样例输出

If So, You Already Have A Google Account. You Can Sign In On The Right.

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
		//corner case
		if(s[0] >= 'a' && s[0] <= 'z')
			s[0] += ('A' - 'a');
		for(int i = 0; i < s.size(); i++) {
			if(s[i] == ' ' || s[i] == '\t' || s[i] == '\r' || s[i] == '\n') {
				if(i + 1 == s.size()) {
					break;
				} else if(s[i+1] >= 'a' && s[i+1] <= 'z') {
					s[i+1] += ('A' - 'a');
				}
			}
		}
		//output
		printf("%s\n", s.c_str());
	}
	
	return 0;
}
