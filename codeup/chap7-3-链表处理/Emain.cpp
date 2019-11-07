#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1000000;
int ele[MAXN];
set<int> st; 

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
		st.clear();
		//input
		for(int i = 0; i < N; i++) {
			scanf("%d", ele+i);
			st.insert(ele[i]);
		}
		sort(ele, ele+N);
		//output
		for(int i = 0; i < N; i++) {
			if(i != 0) printf(" ");
			printf("%d", ele[i]);
		}	printf("\n");
		for(set<int>::iterator it = st.begin(); it != st.end(); it++) {
			if(it != st.begin()) printf(" ");
			printf("%d", *it);
		}	printf("\n");
	}
	return 0;
}
