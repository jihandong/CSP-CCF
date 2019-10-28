#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1001;
int Num[MAXN];

int main() {
	//var
	int N;
	//input
	while((scanf("%d", &N)) > 0) {
		for(int i = 0; i < N; i++) {
			scanf("%d", Num+i);	
		}
		//output
		sort(Num, Num+N);
		printf("%d\n", Num[N-1]);
		if(N == 1) {
			printf("-1\n");
		} else { 
			for(int i = 0; i < N-1; i++) {
				if(i != 0) printf(" ");
				printf("%d", Num[i]);
			}	printf("\n");
		}
	}
	return 0; 
}
