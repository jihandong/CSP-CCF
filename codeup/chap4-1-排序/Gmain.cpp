#include<bits/stdc++.h>
using namespace std;

const int MAXN = 10001;
int Num[MAXN];

int main() {
	//var
	int N;
	while((scanf("%d", &N)) > 0) {
		if(N == 0) break;
		//input
		for(int i = 0; i < N; i++) {
			scanf("%d", Num+i); 
		}
		//sort
		sort(Num, Num+N);
		//output
		if(N % 2 == 0) {
			printf("%d\n", (Num[N/2] + Num[N/2-1]) / 2);
		} else {
			printf("%d\n", Num[N/2]);
		}
	}
	return 0;
}

