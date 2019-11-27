/*
MST��primδʹ�����ȶ��� 
*/
#include<bits/stdc++.h>
using namespace std;

const int MAXV = 1000;
const int INF = 0x3FFFFFFF;
struct edge{
	int v;		//�ߵ�Ŀ�궥�� 
	int dis;	//��Ȩ 
	edge() {}
	edge(int _v, int _dis) {
		this->v = _v;
		this->dis = _dis;
	}
};
vector<edge> Adj[MAXV];	//�ڽӱ� 
int n;			//������ 
int m; 			//���� 
int d[MAXV];	//��̾���
bool vis[MAXV] = {false};	//������飺��¼������� 

int prim() {
	fill(d, d+MAXV, INF);
	d[0] = 0;	//ֻ��0�Ŷ��㵽����S�ľ���Ϊ0������ΪINF
	int ans = 0;	//��С�������ı�Ȩ֮�� 
	for(int i = 0; i < n; i++) {
		int u = -1, MIN = INF;
		for(int j = 0; j < n; j++) {	//ѡ��δ���ʶ�����d[]��С��u 
			if(vis[j] == false && d[j] < MIN) {
				u = j;
				MIN = d[j];
			} 
		}
		//�ҵ���С��INF��d[u]����ʣ�µĶ���ͼ���S����ͨ
		if(u == -1) return -1;
		vis[u] = true;	//���u�ѷ���
		ans += d[u];	//���뼯��S����С�ı߼���MST
		for(int j = 0; j < Adj[u].size(); j++) {
			int v = Adj[u][j].v;	//ͨ���ڽӱ�õ�u�ܵ���Ķ���v 
			if(vis[v] == false && Adj[u][j].dis < d[v]) {
				//���vδ��������uΪ�н�����ʹv��S���� 
				d[v] = Adj[u][j].dis;
			}
		}
	}
	return ans; 
} 

int main() {
	while((scanf("%d%d", &n, &m)) == 2) {	//������������
		for(int i = 0; i < MAXV; i++) {	//��ʼ��ͼG 
			Adj[i].clear();
		}
		for(int i = 0; i < m; i++) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);	//����u,v�Լ���Ȩ
			Adj[u].push_back(edge(v, w));
			Adj[v].push_back(edge(u, w));
		}
		int ans = prim();
		printf("%d\n", ans);
	}
	return 0;
}
