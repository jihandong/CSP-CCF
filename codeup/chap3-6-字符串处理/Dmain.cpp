/*
题目描述

输入一个字符串，以回车结束（字符串长度<=100）。该字符串由若干个单词组成，单词之间用一个空格隔开，所有单词区分大小写。现需要将其中的某个单词替换成另一个单词，并输出替换之后的字符串。
输入
多组数据。每组数据输入包括3行，
第1行是包含多个单词的字符串 s，
第2行是待替换的单词a，(长度<=100)
第3行是a将被替换的单词b。(长度<=100)
s, a, b 最前面和最后面都没有空格。
输出
每个测试数据输出只有 1 行，
将s中所有单词a替换成b之后的字符串。
样例输入

I love Tian Qin
I
You

样例输出

You love Tian Qin
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
	//var
	//input
	while(true) {
		if(cin.eof()) break;
		string a, b, s;
		getline(cin, s);
		getline(cin, a);
		getline(cin, b);
		int pos = 0;
		while((pos = s.find(a, pos)) != string::npos) {
			s.replace(pos, a.size(), b);
			pos += b.size();
		}
		//output
		printf("%s\n", s.c_str());
	}
	return 0;
}

