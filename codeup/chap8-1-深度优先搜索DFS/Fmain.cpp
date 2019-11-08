#include<bits/stdc++.h>
using namespace std;

const int MAXN = 20;
bool G[MAXN][MAXN];
bool V[MAXN][MAXN];
pair<int,int>  path[MAXN*MAXN];
int R, C, P, N, M;

int search(int r, int c) {
	if(r == R && c == C) { //good leave
		for(int i = 0; i < P; i++) {
			if(i != 0) printf("->");
			printf("(%d,%d)", path[i].first, path[i].second);
		}	printf("\n");
		return 1;
	} else { //branch && bad leave
		int res = 0;
		//left
		if(r - 1 >= 1 && G[r-1][c] && !V[r-1][c]) {
			path[P] = pair<int,int>(r-1, c);
			V[r-1][c] = true;	//visited
			P++;				//add lenghth
			res += search(r-1, c);
			P--;				//back length
			V[r-1][c] = false;	//not visited
		}
		//up
		if(c - 1 >=1 && G[r][c-1] && !V[r][c-1]) {
			path[P] = pair<int,int>(r, c-1);
			V[r][c-1] = true;	//visited
			P++;				//add lenghth
			res += search(r, c-1);
			P--;				//back length
			V[r][c-1] = false;	//not visited
		}
		//down
		if(c + 1 <= M && G[r][c+1] && !V[r][c+1]) {
			path[P] = pair<int,int>(r, c+1);
			V[r][c+1] = true;	//visited
			P++;				//add lenghth
			res += search(r, c+1);
			P--;				//back length
			V[r][c+1] = false;	//not visited
		}
		//right
		if(r + 1 <= N && G[r+1][c] && !V[r+1][c]) {
			path[P] = pair<int,int>(r+1, c);
			V[r+1][c] = true;	//visited
			P++;				//add lenghth
			res += search(r+1, c);
			P--;				//back length
			V[r+1][c] = false;	//not visited 
		}
		return res;
	}
}

int main() {
	while((scanf("%d%d", &N, &M)) == 2) {
		//initial
		fill(V[0], V[0]+MAXN*MAXN, false);
		//input
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= M; j++) {
				int tmp; scanf("%d", &tmp);
				G[i][j] = tmp > 0;
			}
		}
		int r, c;
		scanf("%d%d", &r, &c);
		scanf("%d%d", &R, &C);
		//output
		path[0] = pair<int,int>(r,c);
		P = 1;
		V[r][c] = true;
		int res = search(r, c);
		if(res == 0) {
			printf("-1\n");
		}
	}
	return 0;
}
