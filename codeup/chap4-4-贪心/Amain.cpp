#include<bits/stdc++.h>
using namespace std;

const int MAXN = 101;
pair<int,int> TV[MAXN];
bool cmp(pair<int,int> p1, pair<int,int> p2) {
	return p1.second < p2.second;
}

int main() {
	//var
	int N;
	while((scanf("%d", &N)) > 0) {
		if(N == 0) break;
		//input
		for(int i = 0; i < N; i++) {
			scanf("%d%d", &(TV[i].first), &(TV[i].second));
		}
		//sort
		sort(TV, TV+N, cmp);
		//count
		int cnt = 0;
		int pre = -1;
		for(int i = 0; i < N; i++) {
			if(TV[i].first >= pre) {
				cnt++;
				pre = TV[i].second;
			}
		}
		//output
		printf("%d\n", cnt);
	}
	return 0;
} 
