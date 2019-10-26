/*
问题 A: 又一版 A+B

题目描述

输入两个不超过整型定义的非负10进制整数A和B(<=2^31-1)，输出A+B的m (1 < m <10)进制数。
输入

输入格式：测试输入包含若干测试用例。每个测试用例占一行，给出m和A，B的值。
当m为0时输入结束。
输出

输出格式：每个测试用例的输出占一行，输出A+B的m进制数。 

样例输入

2 4 5
8 123 456
0

样例输出

1001
1103
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;

int main() {
	//var
	int m;
	LL a, b;
	//loop
	while((scanf("%d%lld%lld", &m, &a, &b)) == 3) {
		LL sum = a + b;
		string s = "";
		//change
		do {
			s += ((sum % m) + '0');
			sum /= m; 
		} while(sum != 0);
		//output
		for(int i = s.size()-1; i >= 0; i--) {
			printf("%c", s[i]);
		}
		printf("\n");
	}
	
	return 0;
} 
