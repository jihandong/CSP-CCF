#include<bits/stdc++.h>
using namespace std;

int Num[11];

int main() {
	//var
	int N;
	while((scanf("%d", &N)) == 1) {
		//corner
		if(N == 0) continue;
		for(int i = 1; i <= N; i++) {
			Num[i] = i;
		}
		do{
			for(int i = 1; i <= N; i++) {
				if(i != 1) printf(" ");
				printf("%d", Num[i]);
			}	printf("\n");
		} while(next_permutation(Num+1, Num+N+1));
	}
	return 0;
} 
