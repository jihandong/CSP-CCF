#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100000;
pair<int,int> Room[MAXN];

bool cmp(pair<int,int> p1, pair<int,int> p2) {
	double j1 = p1.first; double f1 = p1.second;
	double j2 = p2.first; double f2 = p2.second;
	return j1/f1 > j2/f2;
}

int main() {
	//var
	int M, N;
	while((scanf("%d%d", &M, &N)) > 0) {
		if(M == -1 && N == -1) break;
		//input
		for(int i = 0; i < N; i++) {
			scanf("%d%d", &(Room[i].first), &(Room[i].second));
		}
		//sort
		sort(Room, Room+N, cmp);
		//count
		double jb = 0;
		for(int i = 0; i < N; i++) {
			if(M >= Room[i].second) {
				jb += Room[i].first;
				M -= Room[i].second;
			} else if(M > 0) {
				double tmp1 = Room[i].first;
				double tmp2 = M;
				double tmp3 = Room[i].second;
				jb += tmp1 * (tmp2 / tmp3);
				M = 0;
			} else {
				break;
			}
		}
		//output
		printf("%.3lf\n", jb);
	}
	return 0;
}
