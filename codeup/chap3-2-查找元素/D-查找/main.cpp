#include<bits/stdc++.h>
using namespace std;

int N, M;
int Num[101];

int main() {
	while((scanf("%d", &N)) != EOF) {
		for(int i = 0; i < N; i++) {
			scanf("%d", Num+i);
		}
		scanf("%d", &M);
		for(int i = 0; i < M; i++) {
			int val; scanf("%d", &val);
			bool flag = true;
			for(int j = 0; j < N; j++) {
				if(val == Num[j]) {
					printf("YES\n");
					flag = false;
					break;
				}
			}
			if(flag) printf("NO\n");
		}
	}
	return 0;
}
