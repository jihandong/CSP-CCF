#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100001;
bool Exi[MAXN];
bool Red[MAXN];
queue<int> Nq;

void clear_queue(queue<int> &q) {
	queue<int> tmp;
	swap(tmp, q);
}

int main() {
	//var
	int N;
	while((scanf("%d", &N)) > 0) {
		//initial
		fill(Exi, Exi+N, false);
		fill(Red, Red+N, false);
		clear_queue(Nq);
		//input
		for(int i = 0; i < N; i++) {
			int tmp; scanf("%d", &tmp);
			if(Exi[tmp]) { //existed
				Red[tmp] = true;
			} else { //not exist
				Exi[tmp] = true;
				Nq.push(tmp);
			} 
		}
		//output
		while(!Nq.empty() && Red[Nq.front()]) Nq.pop();
		if(Nq.empty()) {
			printf("None\n");
		} else {
			printf("%d\n", Nq.front());
		}
	}
	return 0;
}
