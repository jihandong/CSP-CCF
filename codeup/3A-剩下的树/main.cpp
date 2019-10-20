#include<bits/stdc++.h>
using namespace std;

int L, M;
bool Tree[10010];	//true: cut, false: remain

int main() {
	while(true) {
		scanf("%d%d", &L, &M);
		if (M == 0) break;
		//input
		memset(Tree, false, sizeof(Tree));
		for (int i = 0; i < M; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			for (int j = a; j <= b; j++) { //[a, b] cut
				Tree[j] = true; //cut
			}
		}
		//output
		int count = 0;
		for (int i = 0; i <= L; i++) { //[0, L] check
			if (!Tree[i]) count++;
		}
		printf("%d\n", count);
	}
	return 0;
} 
