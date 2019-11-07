/*
MST：prim未使用优先队列 
*/
#include<bits/stdc++.h>
using namespace std;

const int MAXV = 1000;
const int INF = 0x3FFFFFFF;
struct edge{
	int v;		//边的目标顶点 
	int dis;	//边权 
	edge() {}
	edge(int _v, int _dis) {
		this->v = _v;
		this->dis = _dis;
	}
};
vector<edge> Adj[MAXV];	//邻接表 
int n;			//顶点数 
int m; 			//边数 
int d[MAXV];	//最短距离
bool vis[MAXV] = {false};	//标记数组：记录访问情况 

int prim() {
	fill(d, d+MAXV, INF);
	d[0] = 0;	//只有0号顶点到集合S的距离为0，其余为INF
	int ans = 0;	//最小生成树的边权之和 
	for(int i = 0; i < n; i++) {
		int u = -1, MIN = INF;
		for(int j = 0; j < n; j++) {	//选出未访问顶点中d[]最小的u 
			if(vis[j] == false && d[j] < MIN) {
				u = j;
				MIN = d[j];
			} 
		}
		//找到不小于INF的d[u]，则剩下的顶点和集合S不连通
		if(u == -1) return -1;
		vis[u] = true;	//标记u已访问
		ans += d[u];	//将与集合S距离小的边加入MST
		for(int j = 0; j < Adj[u].size(); j++) {
			int v = Adj[u][j].v;	//通过邻接表得到u能到达的顶点v 
			if(vis[v] == false && Adj[u][j].dis < d[v]) {
				//如果v未访问且以u为中介点可以使v离S更近 
				d[v] = Adj[u][j].dis;
			}
		}
	}
	return ans; 
} 

int main() {
	while((scanf("%d%d", &n, &m)) == 2) {	//顶点数、边数
		for(int i = 0; i < MAXV; i++) {	//初始化图G 
			Adj[i].clear();
		}
		for(int i = 0; i < m; i++) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);	//输入u,v以及边权
			Adj[u].push_back(edge(v, w));
			Adj[v].push_back(edge(u, w));
		}
		int ans = prim();
		printf("%d\n", ans);
	}
	return 0;
}
