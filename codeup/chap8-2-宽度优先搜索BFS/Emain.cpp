#include<bits/stdc++.h>
using namespace std;

const int MAXN = 101*101*101 + 1;
bool HT[MAXN];
int ABC[3], K;
struct node{
	int abc[3] ;
	int L;
	node (){}
	node (int _a, int _b, int _c, int _L) {
		this->abc[0] = _a;
		this->abc[1] = _b;
		this->abc[2] = _c;
		this->L = _L;
	}
};

int hashTable(node n) {
	return (n.abc[0]*101 + n.abc[1])*101 + n.abc[2];
} 

node opab(node n, int s, int t) {
	n.abc[t] += n.abc[s];
	n.abc[s] = 0;
	if(n.abc[t] > ABC[t]) {
		n.abc[s] = (n.abc[t] - ABC[t]);
		n.abc[t] = ABC[t];
	}
	n.L++;
	return n;
}

void test(node n) {
	printf("%d %d %d %d\n", n.abc[0], n.abc[1], n.abc[2], n.L);
}

void bfs(node n0) {
	queue<node> q;
	q.push(n0);
	while(!q.empty()) {
		node n = q.front();
		q.pop();
		//test(n);
		//leave
		if(n.abc[0] == K || n.abc[1] == K || n.abc[2] == K) {
			printf("yes\n%d\n", n.L);
			return;
		}
		//branch
		node tmp;
		tmp = opab(n, 0, 1); if(!HT[hashTable(tmp)]) { HT[hashTable(tmp)] = true; q.push(tmp); }
		tmp = opab(n, 0, 2); if(!HT[hashTable(tmp)]) { HT[hashTable(tmp)] = true; q.push(tmp); }
		tmp = opab(n, 1, 0); if(!HT[hashTable(tmp)]) { HT[hashTable(tmp)] = true; q.push(tmp); }
		tmp = opab(n, 1, 2); if(!HT[hashTable(tmp)]) { HT[hashTable(tmp)] = true; q.push(tmp); }
		tmp = opab(n, 2, 0); if(!HT[hashTable(tmp)]) { HT[hashTable(tmp)] = true; q.push(tmp); }
		tmp = opab(n, 2, 1); if(!HT[hashTable(tmp)]) { HT[hashTable(tmp)] = true; q.push(tmp); }
	}
	printf("no\n");
}

int main() {
	while(scanf("%d%d%d%d", &ABC[0], &ABC[1], &ABC[2], &K) == 4) {
		//initial
		fill(HT, HT+MAXN, false);
		//output
		node s = node(ABC[0], 0, 0, 0);
		HT[hashTable(s)] = true;
		bfs(s);
	}
	return 0;
} 
