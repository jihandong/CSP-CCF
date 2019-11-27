#include<bits/stdc++.h>
using namespace std;

struct node{
	vector<vector<int> > v;
	int x, y, d;
	node() {}
	node(vector<vector<int> > _v, int _x, int _y, int _d) {
		this->v = _v;
		this->x = _x;
		this->y = _y;
		this->d = _d;
	}	
};
vector<vector<int> > V = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

int hashT(vector<vector<int> > v) {
	for(int i = 0; )
}

void bfs(node n) {
	queue<node> q;
	q.push(n);
	while(!q.empty()) {
		vector<vector<int> > v = q.top().v;
		int x = q.top().x;
		int y = q.top().y;
		int d = q.top().d;
		if(v == V) {
			return 
		}
		q.pop();
		if(x + 1 < 3) {
			vector<vector<int> > v1(v);
			swap(v1[x][y], v1[x+1][y]);
			q.push(node(v1, x+1, y, n+1));
		}
		if(y + 1 < 3) {
			vector<vector<int> > v1(v);
			swap(v1[x][y], v1[x][y+1]);
			q.push(node(v1, x, y+1, n+1));
		}
		if(x - 1 >= 0) {
			vector<vector<int> > v1(v);
			swap(v1[x][y], v1[x-1][y]);
			q.push(node(v1, x-1, y, n+1));
		}
		if(y - 1 >= 0) {
			vector<vector<int> > v1(v);
			swap(v1[x][y], v1[x][y-1]);
			q.push(node(v1, x, y-1, n+1));
		}
	}
}

int main() {
	//var
	node n = node({{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}, 0, 0, 0);
	while((scanf("%d%d%d", &(n.v[0][0])), &(n.v[0][1])), &(n.v[0][2]))) == 3) {
		//input start
		for(int i = 1; i < 3; i++) {
			for(int j = 0; j < 3; j++) {
				scanf("%d", &(n.v[i][j]));
			}
		}
		//input end
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 3; j++) {
				scanf("%d", &V[i][j]);
			}
		}
		//bfs
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 3; j++) {
				if(n.v[i][j] == 0) {
					n.x = i;
					n.y = j;
					break;
				}
			}
		}
		//bfs
		n.d = 1;
		bfs(n);
		//output
		
	}
	return 0;
}

