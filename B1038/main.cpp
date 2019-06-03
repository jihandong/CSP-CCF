#include<cstdio>

int N, K;
int HashTable[101];
int S[100010];

int main() {
	scanf("%d", &N);
	int grade;
	for(int i = 0; i < N; i++) {
		scanf("%d", &grade);
		HashTable[grade]++;
	}
	scanf("%d", &K);
	for(int i = 0; i < K; i++)
		scanf("%d", &S[i]);
	for(int i = 0; i < K; i++) {
		printf("%d", HashTable[S[i]]);
		if(i == K - 1) printf("\n");
		else printf(" ");
	}
	return 0;
}
