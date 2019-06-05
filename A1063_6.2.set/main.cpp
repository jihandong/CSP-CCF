#include<cstdio>
#include<set>
using namespace std;

int N, M, K, P1, P2;
int Q1[2000], Q2[2000];
set<int> S[50];
int I, U;

int main() {
	scanf("%d", &N);
	for(int i = 0; i < N; i++) {
		scanf("%d", &M);
		for(int j = 0; j < M; j++) {
			int buf;
			scanf("%d", &buf);
			S[i].insert(buf);
		}	
	}
	scanf("%d", &K);
	for(int i = 0; i < K; i++) scanf("%d%d", Q1 + i, Q2 + i);
	for(int i = 0; i < K; i++) {
		int P1 = Q1[i] - 1, P2 = Q2[i] - 1;
		set<int>::iterator it;
		for(it = S[P1].begin(); it != S[P1].end(); it++) {
			if(S[P2].find(*it) != S[P2].end()) I++;
		}
		U = S[P1].size() + S[P2].size() - I;
		printf("%.1f\%\n", (I * 100.0) / U);
		I = 0; U = 0;
	}
	return 0;
}
