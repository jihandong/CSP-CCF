#include<bits/stdc++.h>
using namespace std;

int N, X;
int Num[201];

int main() {
	while((scanf("%d", &N)) != EOF) {
		for(int i = 0; i < N; i++) {
			scanf("%d", Num + i);
		}
		scanf("%d", &X);
		int label = -1;
		for(int i = 0; i < N; i++) {
			if(Num[i] == X) {
				label = i;
				break;
			}
		}
		printf("%d\n", label);
	}
	return 0;
}
