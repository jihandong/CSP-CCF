#include<bits/stdc++.h>
using namespace std;

const int MAXN = 8;
char G[MAXN][MAXN];
struct node{
	int r, c, t;
	node() {}
	node(int _r, int _c, int _t) {
		this->r = _r;
		this->c = _c;
		this->t = _t;
	}
};

/*
void test(queue<node> q) {
	queue<node> tmp;
	while(!q.empty()) {
		printf("(%d,%d,%d)", q.front().r, q.front().c, q.front().t);
		tmp.push(q.front());
		q.pop();
	}	printf("\n");
	swap(tmp, q);
}*/

bool safe(int r, int c, int t) {
	if(!(r >= 0 && r < MAXN && c >= 0 && c < MAXN)) { //check pos
		return false;
	} else if(	
		(r + t >= MAXN || (r + t < MAXN && G[r + t][c] != 'S')) && //can go
		(r+t+1 >= MAXN || (r+t+1 < MAXN && G[r+t+1][c] != 'S')) ) { //go then not die
		return true;
	} else {
		return false;
	}
}

bool absafe(int r, int c, int t) {
	bool flag = true;
	for(int i = r+t; i < MAXN; i++) {
		if(G[i][c] == 'S') {
			flag = false;
			break;
		}
	}
	return flag;
}

bool bfs() {
	int t = 0;
	queue<node> q;
	q.push(node(0,0,0));
	while(!q.empty()) {
		//test(q);
		int r = q.front().r;
		int c = q.front().c;
		int t = q.front().t;
		q.pop();
		if(absafe(r, c, t)) return true;
		int cnt = 0;
		if(safe(r-1, c-1, t)) { cnt += 1; q.push(node(r-1,c-1,t+1)); } //
		if(safe(r-1, c  , t)) { cnt += 1; q.push(node(r-1,c  ,t+1)); } //
		if(safe(r-1, c+1, t)) { cnt += 1; q.push(node(r-1,c+1,t+1)); } //
		if(safe(r  , c-1, t)) { cnt += 1; q.push(node(r  ,c-1,t+1)); } //
		if(safe(r  , c  , t)) { cnt += 1; q.push(node(r  ,c  ,t+1)); } //
		if(safe(r  , c+1, t)) { cnt += 1; q.push(node(r  ,c+1,t+1)); } //
		if(safe(r+1, c-1, t)) { cnt += 1; q.push(node(r+1,c-1,t+1)); } //
		if(safe(r+1, c  , t)) { cnt += 1; q.push(node(r+1,c  ,t+1)); } //
		if(safe(r+1, c+1, t)) { cnt += 1; q.push(node(r+1,c+1,t+1)); } //
		if(t+1 == MAXN && cnt > 0) return true;
	}
	return false;
}

int main() {
	//var
	int N;
	string s;
	scanf("%d%*c", &N);
	for(int i = 1; i <= N; i++) {
		//corner
		//initial
		//input
		for(int j = MAXN-1; j >= 0; j--) {
			getline(cin, s);
			for(int k = 0; k < MAXN; k++) {
				G[j][k] = s[k];
			}
		}
		//output
		if(bfs()) {
			printf("Case #%d: Yes\n", i);
		} else {
			printf("Case #%d: No\n", i);
		}
		//next
		getline(cin, s);
	}
	return 0;
}
