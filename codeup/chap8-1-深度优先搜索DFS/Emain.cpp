#include<bits/stdc++.h>
using namespace std;

const int MAXN = 11;
int Q[MAXN];

int cnt(int i, int o, int s) {
	if(s < 0) {	//cut branch
		return 0;
	} else if(i == 0 && o == 0) { //good leave
		return 1;
	} else { //branch or bad leave
		int res1 = (i > 0)? cnt(i-1, o, s+1) : 0; //push
		int res2 = (o > 0)? cnt(i, o-1, s-1) : 0; //pop
		return res1 + res2;
	}
}

int main() {
	//var
	int N;
	while((scanf("%d", &N)) == 1) {
		//corner
		if(N == 0) {
			continue;
		} else if(N == 1) {
			printf("1\n");
			continue;
		}
		//initial
		for(int i = 1; i <= N; i++) {
			Q[i] = i;
		}
		//input
		printf("%d\n", cnt(N, N, 0)); 
	}
	return 0;
}
