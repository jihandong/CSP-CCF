/*
谁是你的潜在朋友

题目描述

    “臭味相投”——这是我们描述朋友时喜欢用的词汇。两个人是朋友通常意味着他们存在着许多共同的兴趣。然而作为一个宅男，你发现自己与他人相互了解的机会 并不太多。幸运的是，你意外得到了一份北大图书馆的图书借阅记录，于是你挑灯熬夜地编程，想从中发现潜在的朋友。
    首先你对借阅记录进行了一番整理，把N个读者依次编号为1,2,…,N，把M本书依次编号为1,2,…,M。同时，按照“臭味相投”的原则，和你喜欢读同一本书的人，就是你的潜在朋友。你现在的任务是从这份借阅记录中计算出每个人有几个潜在朋友。
输入

    每个案例第一行两个整数N,M，2 <= N ，M<= 200。接下来有N行，第i(i = 1,2,…,N)行每一行有一个数，表示读者i-1最喜欢的图书的编号P(1<=P<=M)
输出

    每个案例包括N行，每行一个数，第i行的数表示读者i有几个潜在朋友。如果i和任何人都没有共同喜欢的书，则输出“BeiJu”（即悲剧，^ ^）
样例输入

4 5
2
3
2
1

样例输出

1
BeiJu
1
BeiJu

*/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 201;
const int MAXM = 201;
int Fav[MAXN];
int Book[MAXM];

int main() {
	//var
	int N, M;
	while((scanf("%d%d", &N, &M)) > 0) {
		//initial
		fill(Fav, Fav+N, 0);
		fill(Book, Book+M, 0);
		//input
		for(int i = 0; i < N; i++) {
			int b; scanf("%d", &b);
			Fav[i] = b;
			Book[b]++;
		}
		//output
		for(int i = 0; i < N; i++) {
			int cnt = Book[Fav[i]] - 1;
			if(cnt > 0) {
				printf("%d\n", cnt);
			} else {
				printf("BeiJu\n");
			}
		}
	}
	return 0;
} 
