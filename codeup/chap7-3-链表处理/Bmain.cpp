#include<bits/stdc++.h>
using namespace std;

set<pair<int,int> > st;

int main() {
	//var
	int N, M;
	while((scanf("%d%d", &N, &M)) == 2) {
		//input
		for(int i = 0; i < N+M; i++) {
			int a, b; scanf("%d%d", &a, &b);
			st.insert(pair<int,int>(a, b));
		}
		//output
		for(set<pair<int,int> >::iterator it = st.begin(); it != st.end(); it++) {
			printf("%d %d\n", it->first, it->second);
		}
	}
	return 0;	
}
