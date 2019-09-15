/*
 * 1.dijkstra超时：没有使用优先队列导致失去20分，尽可能使用优先队列
 */
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100001;
const int INF = 0x3FFFFFFF;
int n, m;
struct node {
	int v, dis;
	node(int _v, int _dis) {v = _v; dis = _dis;};
	friend bool operator < (node n1, node n2) {
		return n1.dis < n2.dis;
	} 
};
vector<node> Adj[MAXN];
int d[MAXN];
bool vis[MAXN] = {false};

void dijkstra(int s) {
	fill(d, d + MAXN, INF);
	d[s] = 0;
	for (int i = 0; i < n; i++) { //choose nearest (u)
		int u = -1, MIN = INF;
		for (int j = 0; j < n; j++) {
			if (vis[j] == false && d[j] < MIN) {
				u = j;
				MIN = d[j];
			}
		}
		if (u == -1) return;
		vis[u] = true;
		for (int j = 0; j < Adj[u].size(); j++) { //each neighbor of u
			int v = Adj[u][j].v;
			if (vis[v] == false && d[v] > max(d[u], Adj[u][j].dis)) {
				d[v] = max(d[u], Adj[u][j].dis); //better d[v]
			}
		}
	}
}

void i_graph() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		Adj[a-1].push_back(node(b-1, c));
		Adj[b-1].push_back(node(a-1, c));
	}
	return;
}

void o_length() {
	printf("%d\n", d[n-1]);
	return;
}

int main() {
	i_graph(); 
	dijkstra(0); //means 1
	o_length();
	return 0; 
}
