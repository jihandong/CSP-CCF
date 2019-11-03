#include<bits/stdc++.h>
using namespace std;

const int MAXN = 51;
set<int> St[MAXN];

int main() {
	//var
	int N, Ni, M;
	while((scanf("%d", &N)) > 0) {
		//initial
		for(int i = 0; i < N; i++) {
			St[i].clear();
		}
		//intput set
		for(int i = 1; i <= N; i++) {
			scanf("%d", &Ni);
			for(int j = 0; j < Ni; j++) {
				int tmp; scanf("%d", &tmp);
				St[i].insert(tmp);
			}
		}
		//serch
		scanf("%d", &M);
		for(int i = 0; i < M; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			set<int> s, u;
			set_intersection(St[a].begin(), St[a].end(), St[b].begin(), St[b].end(), inserter(s, s.begin()));
			set_union		(St[a].begin(), St[a].end(), St[b].begin(), St[b].end(), inserter(u, u.begin()));
			double s_size = s.size();
			double u_size = u.size();
			printf("%.1lf%\n", s_size/u_size * 100); 
		}
	}
		
	return 0;
}
