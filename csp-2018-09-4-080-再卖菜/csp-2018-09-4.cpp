/*
 * 1.dfs用于暴力搜索和剪枝：注意在合适的时候剪去枝叶来得到满分
 */
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 301;
const int MAXP = 100;
int n;
int now[MAXN];
int pre[MAXN];
bool mem[MAXN][MAXP][MAXP];

void input() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", now + i);
}

void output() {
	for (int i = 1; i <= n; i++) {
		if(i != 1) printf(" ");
		printf("%d", pre[i]);
	} printf("\n");
	exit(0);
}

void dfs(int index, int price) {
	//branch cut
	if (index > 1) {
		if (mem[index][price][pre[index-1]]) return;
	}
	mem[index][price][pre[index-1]] = true;
	//branch out
	int p;
	pre[index] = price;
	/* 
	if (index == 1) printf("index1 is %d\n", price);
	if (index == 2) printf(" index2 is %d\n", price);
	if (index == 3) printf("  index3 is %d\n", price);
	if (index == 4) printf("   index4 is %d\n", price);
	if (index == 5) printf("    index5 is %d\n", price);
	if (index == 6) printf("     index6 is %d\n", price);
	if (index == 7) printf("      index7 is %d\n", price);
	if (index == 8) printf("       index8 is %d\n", price);
	*/ 
	if (index == 0) {
		for (int i = 1; i < 2*now[1]+1; i++) 
			dfs(1, i);
	} else if (index == 1) {
		if ((p = 2*now[1] - pre[1]) > 0) dfs(2, p);
		if ((p = 2*now[1] - pre[1] + 1) > 0) dfs(2, p);
	} else if (index < n) {
		if ((p = 3*now[index] - pre[index] - pre[index-1]) > 0) dfs(index + 1, p);
		if ((p = 3*now[index] - pre[index] - pre[index-1] + 1) > 0) dfs(index + 1, p);
		if ((p = 3*now[index] - pre[index] - pre[index-1] + 2) > 0) dfs(index + 1, p);
	} else {
		if (pre[n-1] + pre[n] == 2*now[n]) output();
		if (pre[n-1] + pre[n] == 2*now[n] + 1) output();
	}
}

int main() {
	input();
	dfs(0, 0);
	return 0;
} 
