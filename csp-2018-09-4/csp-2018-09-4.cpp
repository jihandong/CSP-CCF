/*
 * 1.dfs用于暴力搜索和剪枝：注意在合适的时候剪去枝叶来得到满分
 */
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 301;
int n;
int now[MAXN];
int pre[MAXN];
bool flag = false;

void input() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", now + i);
}

void output() {
	for (int i = 1; i <= n; i++) {
		if(i != 1) printf(" ");
		printf("%d", pre[i]);
	} printf("\n");
}

void dfs(int index, int price) {
	//branch
	int p;
	if (flag) return;
	else pre[index] = price;
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
			if (!flag) dfs(1, i);
	} else if (index == 1) {
		if (!flag && (p = 2*now[1] - pre[1]) > 0) dfs(2, p);
		if (!flag && (p = 2*now[1] - pre[1] + 1) > 0) dfs(2, p);
	} else if (index < n) {
		if (!flag && (p = 3*now[index] - pre[index] - pre[index-1]) > 0) dfs(index + 1, p);
		if (!flag && (p = 3*now[index] - pre[index] - pre[index-1] + 1) > 0) dfs(index + 1, p);
		if (!flag && (p = 3*now[index] - pre[index] - pre[index-1] + 2) > 0) dfs(index + 1, p);
	} else {
		if (!flag && pre[n-1] + pre[n] == 2*now[n]) flag = true;
		if (!flag && pre[n-1] + pre[n] == 2*now[n] + 1) flag = true;
	}
}

int main() {
	input();
	dfs(0, 0);
	output();
	return 0;
} 
