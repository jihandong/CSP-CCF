#include<bits/stdc++.h>
using namespace std;

const int MAXN = 601;
int Blk[MAXN];

int cmp(int i, int j) {
	return i > j;
}

int main() {
	//var
	int L, N;
	while((scanf("%d%d", &L, &N)) > 0) {
		//initial
		fill(Blk, Blk+N, 0);
		//input
		for(int i = 0; i < N; i++) {
			scanf("%d", &Blk[i]);
		}
		//sort
		sort(Blk, Blk+N, cmp);
		//count
		int cnt = 0, len = 0;
		for(int i = 0; i < N; i++) {
			len += Blk[i];
			cnt++;
			if(len >= L) break; 
		}
		//output
		if(len < L) {
			printf("impossible\n");
		} else {
			printf("%d\n", cnt);
		}
	}
	return 0;
}
