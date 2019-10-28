/*
题目描述

请写一个程序，对于一个m行m列的（1<m<10）的方阵，求其每一行，每一列及主对角线元素之和，最后按照从大到小的顺序依次输出。
输入

共一组数据，输入的第一行为一个正整数，表示m，接下来的m行，每行m个整数表示方阵元素。
输出

从大到小排列的一行整数，每个整数后跟一个空格，最后换行。
样例输入

4
15 8 -2 6
31 24 18 71
-3 -9 27 13
17 21 38 69

样例输出

159 145 144 135 81 60 44 32 28 27

*/
#include<bits/stdc++.h>
using namespace std;

const int MAXM = 10;
int Mat[MAXM][MAXM];
int Res[2*MAXM+2];

bool cmp(int i, int j) {
	return i > j;
}

int main() {
	//var
	int M;
	//intput
	while((scanf("%d", &M)) > 0) {
		for(int i = 0; i < M; i++) {
			for(int j = 0; j < M; j++) {
				scanf("%d", &Mat[i][j]);
			}
		}
		//count row
		for(int i = 0; i < M; i++) {
			int cnt = 0;
			for(int j = 0; j < M; j++) {
				cnt += Mat[i][j]; //row
			}
			Res[i] = cnt;
		}
		//count col
		for(int i = 0; i < M; i++) {
			int cnt = 0;
			for(int j = 0; j < M; j++) {
				cnt += Mat[j][i]; //col
			}
			Res[M + i] = cnt;
		}
		//count diag
		int cnt1 = 0, cnt2 = 0;
		for(int i = 0; i < M; i++) {
			cnt1 += Mat[i][i];
			cnt2 += Mat[i][M-1-i]; 
		}
		Res[2*M] = cnt1; Res[2*M+1] = cnt2;
			//sort
		sort(Res, Res + (2*M+2), cmp);
		//output
		for(int i = 0; i < (2*M+2); i++) {
		if(i != 0) printf(" ");
				printf("%d", Res[i]);
		}	printf("\n");
	}
	return 0; 
}
