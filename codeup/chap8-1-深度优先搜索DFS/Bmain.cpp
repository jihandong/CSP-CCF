#include<bits/stdc++.h>
using namespace std;

int N, R;
void permutation(vector<int> v, int n) {
	if (v.size() == R) {
		for(int i = 0; i < R; i++) {
			if(i != 0) printf(" ");
			printf("%d", v[i]);
		}	printf("\n");
	} else if(n > N) {	//out of range
		return;
	} else { //branch
		vector<int> v2(v);
		v.push_back(n);
		permutation(v, n+1);
		permutation(v2, n+1);
	}
}

int main() {
	while((scanf("%d%d", &N, &R)) == 2) {
		vector<int> v;
		permutation(v, 1);
	}
	return 0; 
}
