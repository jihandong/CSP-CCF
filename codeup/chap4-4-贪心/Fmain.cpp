#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2000;
int Per[MAXN];

int main() {
	//var
	int C, N, V, W;
	//input
	scanf("%d", &C);
	for(int i = 0; i < C; i++) {
		scanf("%d%d%d", &N, &V, &W);
		//input percent
		for(int j = 0; j < N; j++) {
			scanf("%d", &Per[j]);
		}
		//sort
		sort(Per, Per+N);
		//make psion
		int p = 0, cnt = 0;
		for(int j = 0; j < N; j++) {
			double plf = p + Per[j]; 
			if(plf / (j+1) <= W) {
				p += Per[j];
				cnt++;
			} else {
				break;
			}
		}
		//output
		double plf = p;
		if(cnt == 0) {
			printf("0 0.00\n");
		} else {
			printf("%d %.2lf\n", cnt * V, plf / (100*cnt));
		}
	}
	return 0;
}
