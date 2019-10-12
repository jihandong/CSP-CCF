/* 通信网络：100
 * 1.图存储形式：即使只有V1000-E10000，也不应该用邻接矩阵，遍历起来还是太慢了，必须尽量用邻接链表
 */
#include<bits/stdc++.h>
using namespace std;

const int MAXV = 1000;
int n, m, c;
vector<int> Adj[MAXV];
vector<int> Adji[MAXV];
bool inq[MAXV] = {false};
bool inqi[MAXV] = {false};

void bfs(int u) {
	fill(inq, inq + n, false); //initial
	fill(inqi, inqi + n, false); //initial
	queue<int> q, qi;
	q.push(u); qi.push(u);
	inq[u] = true; inqi[u] = true;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(int i = 0; i < Adj[u].size(); i++) {
			int v = Adj[u][i];
			if (inq[v] == false) {
				q.push(v);
				inq[v] = true;
			}
		}
	}
	while(!qi.empty()) {
		int u = qi.front();
		qi.pop();
		for(int i = 0; i < Adji[u].size(); i++) {
			int v = Adji[u][i];
			if (inqi[v] == false) {
				qi.push(v);
				inqi[v] = true;
			}
		}
	}
	
	/*test
	printf("%d:\n", u+1);
	for(int i = 0; i < n; i++) {
		if(inq[i]) printf(" %d", i+1);
	} printf("\n");
	for(int i = 0; i < n; i++) {
		if(inqi[i]) printf(" %d", i+1);
	} printf("\n");
	*/
	int count = 0;
	for(int i = 0; i < n; i++)
		if (inq[i] || inqi[i]) count++;
	if (count == n) c++;
}

void bfs_trave() {
	for (int i = 0; i < n; i++) {
		bfs(i);
	}
}

void input() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		Adj[a-1].push_back(b-1);
		Adji[b-1].push_back(a-1); 
	} 
}

void output() {
	printf("%d\n", c);
}

int main() {
	input();
	bfs_trave();
	output();
	return 0;
}
