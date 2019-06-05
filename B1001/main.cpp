#include<cstdio>

int N; 

int main() { 
	scanf("%d", &N);
	int time = 0;
	while(N != 1) {
		if(N % 2 == 0) N = N / 2;
		else N = (3 * N + 1) / 2;
		time++;
	}
	printf("%d", time);
	return 0;
}
	
