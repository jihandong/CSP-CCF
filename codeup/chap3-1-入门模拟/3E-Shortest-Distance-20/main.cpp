#include<bits/stdc++.h>
using namespace std;

int N, M;
int D[100010];

int shortest(int a, int b){
	int min = (a < b)? a : b;
	int max = (a < b)? b : a;
	//min-max
	int res1 = 0;
	for(int i = min; i < max; i++) {
		res1 += D[i];
	}
	//max-min
	int res2 = 0;
	for(int i = 1; i < min; i++) {
		res2 += D[i];
	}
	for(int i = max; i <= N; i++) {
		res2 += D[i];
	}
	return (res1 < res2)? res1 : res2;
}

int main() {
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d", &D[i+1]);
	}
	scanf("%d", &M);
	for(int i = 0; i < M; i++){
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", shortest(a, b));
	}
	return 0;
}
