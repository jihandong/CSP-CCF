#include<bits/stdc++.h>
using namespace std;

const int MAXV = 101;
const int MAXE = 10001;
//�����ݽṹ 
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

//���鼯��� 
int father[MAXV];	//���鼯
int find_father(int x) {
	int a = x;
	while(x != father[x]) {
		x = father[x];	//xΪ�� 
	}
	//·��ѹ����ȫ���ӵ�x�� 
	while(a != father[a]) {
		int z = a;
		a = father[a];
		father[a] = x;
	} 
}

//kruskal����MST�ı�Ȩ֮�ͣ�n�����������m��ͼ���� 
int kruskal(int n, int m) {
	//ansΪ��Ȩ֮��
	int ans = 0, NUM_EDGE = 0;
	for(int i = 1; i <= n; i++) {	//���㷶Χ[1,n] 
		father[i] = i;	//���鼯��ʼ�� 
	}
	for(int i = 0; i < m; i++) {	//ö�ٱ� 
		int faU = find_father(E[i].u);	 //��ѯ���ڼ�
		int faV = find_father(E[i].v);	
		if(faU != faV) {	//����һ�����ϾͿ��Լ��� 
			father[faU] = faV;	//�ϲ�����
			ans += E[i].w;
			NUM_EDGE++;
			if(NUM_EDGE == n-1) break; //MST�Ѿ��γ� 
		} 
	}
	if(NUM_EDGE != n-1)
		return -1; //����ͨ 
	else
		return ans; 
} 

int main() {
	int n, m;
	//ÿ������ 
	while((scanf("%d%d", &n, &m)) == 2) {
		for(int i = 0; i < m; i++) {
			scanf("%d%d%d", &E[i].u, &E[i].v, &E[i].w);	
		}
		int ans = kruskal(n, m);
		printf("%d\n", ans); 
	} 
	return 0;
}
