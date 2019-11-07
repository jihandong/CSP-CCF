#include<bits/stdc++.h>
using namespace std;

vector<int> v;

void clear_vector(vector<int> v) {
	vector<int> tmp;
	swap(tmp, v);
}

int main() {
	//var
	int N;
	while((scanf("%d", &N)) == 1) {
		//corner
		if(N == 0) {
			printf("list is empty\n");
			continue;
		}
		//initial
		clear_vector(v);
		//input
		for(int i = 0; i < N; i++) {
			int tmp; scanf("%d", &tmp); 
			v.push_back(tmp);
		}
		//output
		for(int i = 0; i < N; i++) {
			if(i != 0) printf(" ");
			printf("%d", v[i]);
		}	printf("\n");
		for(int i = N-1; i >= 0; i--) {
			if(i != N-1) printf(" ");
			printf("%d", v[i]);
		}	printf("\n");
	}
	return 0;
}
