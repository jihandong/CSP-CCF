#include<bits/stdc++.h>
using namespace std;

const int MAXV = 100001; 
const int MAXE = 200001;
int n, m;
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
	while(a != father[x]) {
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
}

int kruskal() {
	int num_edge = 0;
	for (int i = 1; i <= n; i++) { //initial union-find-set
		father[i] = i;
	}
	sort(E, E + m, cmp); //light -> heavy
	for (int i = 0; i < m; i++) {
		int faU = find_father(E[i].u);
		int faV = find_father(E[i].v);
		if (faU != faV) {
			father[faU] = faV;
			num_edge++;
			if (num_edge == n - 1)
				return E[i].cost;
			int fa1 = find_father(1);
			int faN = find_father(n);
			if (fa1 == faN)
				return E[i].cost;
	 	}
	}
}

void input() {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++)
		scanf("%d%d%d", &(E[i].u), &(E[i].v), &(E[i].cost));
}

void output() {
	printf("%d\n", kruskal());
}


int main() {
	input();
	output();
	return 0;
} 
