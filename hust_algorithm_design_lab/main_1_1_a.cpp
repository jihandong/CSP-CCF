#include<bits/stdc++.h>
using namespace std;

const int MAXV = 101;
const int MAXE = 10001;
//边数据结构 
struct edge{
	int u, v, w;
	edge() {}
	friend bool operator < (edge e1, edge e2) {
		return e1.w >= e2.w;
	}
} E[MAXE];
bool cmp(edge e1, edge e2) {
	return e1.w < e2.w;
}
priority_queue<edge> pq;

//并查集设计 
int father[MAXV];	//并查集
int find_father(int x) {
	int a = x;
	while(x != father[x]) {
		x = father[x];	//x为根 
	}
	//路径压缩，全部接到x上 
	while(a != father[a]) {
		int z = a;
		a = father[a];
		father[a] = x;
	} 
}

//kruskal返回MST的边权之和，n：顶点个数，m：图边数 
int kruskal(int n, int m) {
	//ans为边权之和
	int ans = 0, NUM_EDGE = 0;
	for(int i = 1; i <= n; i++) {	//顶点范围[1,n] 
		father[i] = i;	//并查集初始化 
	}
	for(int i = 0; i < m; i++) {	//枚举边 
		int faU = find_father(E[i].u);	 //查询所在集
		int faV = find_father(E[i].v);	
		if(faU != faV) {	//不在一个集合就可以加入 
			father[faU] = faV;	//合并集合
			ans += E[i].w;
			NUM_EDGE++;
			if(NUM_EDGE == n-1) break; //MST已经形成 
		} 
	}
	if(NUM_EDGE != n-1)
		return -1; //无联通 
	else
		return ans; 
} 

int main() {
	int n, m;
	//每组输入 
	while((scanf("%d%d", &n, &m)) == 2) {
		for(int i = 0; i < m; i++) {
			scanf("%d%d%d", &E[i].u, &E[i].v, &E[i].w);	
		}
		int ans = kruskal(n, m);
		printf("%d\n", ans); 
	} 
	return 0;
}
