/* 数据中心：100
 */
#include<bits/stdc++.h>
using namespace std;

const int MAXE = 100001;
const int MAXV = 50001;
int n, m, root;
struct edge {
	int u, v;
	int cost;
} E[MAXE];
int father[MAXV];

bool cmp(edge a, edge b) {
	return a.cost < b.cost;
}

int find_father(int x) {
	int a = x;
	while(x != father[x]) x = father[x];
	while(a != father[a]) {
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
}

int kruskal() {
	int num_edge = 0;
	for(int i = 1; i <= n; i++) {
		father[i] = i;
	}
	sort(E, E + m, cmp);
	for(int i = 0; i < m; i++) {
		int faU = find_father(E[i].u);
		int faV = find_father(E[i].v);
		if (faU != faV){
			father[faU] = faV;
			num_edge++;
			if (num_edge == n - 1) return E[i].cost;
		}
	}
}

void input() {
	scanf("%d%d%d", &n, &m, &root);
	for(int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		E[i].u = a - 1;
		E[i].v = b - 1;
		E[i].cost = c;
	}
}

void output() {
	printf("%d\n", kruskal()); 
}

int main() {
	input();
	output();
	return 0;
}
