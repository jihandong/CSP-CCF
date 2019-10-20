#include<bits/stdc++.h>
using namespace std;

int N;
int Grade[1001]; 

int main() {
	while(true) {
		scanf("%d", &N);
		if(N == 0) break;
		//input grade
		for(int i = 0; i < N; i++)
			scanf("%d", Grade + i);
		int line;
		scanf("%d", &line);
		//output
		int cnt = 0;
		for(int i = 0; i < N; i++) {
			if(Grade[i] == line) cnt++;
		}
		printf("%d\n", cnt);
	} 
	return 0;
} 
