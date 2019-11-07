#include<bits/stdc++.h>
using namespace std;

vector<int> v1;
vector<int> v2;

int main() {
	//var
	int N, M;
	while((scanf("%d", &N)) == 1) {
		//initial
		v1.clear();
		v2.clear();
		//input
		for(int i = 0; i < N; i++) {
			int tmp; scanf("%d", &tmp);
			v1.push_back(tmp);
		}
		scanf("%d", &M);
		for(int i = 0; i < M; i++) {
			int tmp; scanf("%d", &tmp);
			v2.push_back(tmp);
		}
		//output
		for(int i = 0; i < N; i++) {
			if(i != 0) printf(" ");
			printf("%d", v1[i]);
		}
		for(int i = 0; i < M; i++) {
			if(!(N == 0 && i == 0)) printf(" ");
			printf("%d", v2[i]);
		}	printf("\n");
	}
	return 0;
}
