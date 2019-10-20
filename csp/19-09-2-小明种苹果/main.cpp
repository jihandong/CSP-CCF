#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1001;
int N;
int Tree[MAXN];
bool Drop[MAXN] = {false};
int T, D, E;

int main() {
	//input
	scanf("%d", &N);
	for (int i = 0; i < N; i++) { //i : tree No. 
		int m; scanf("%d", &m);
		for (int j = 0; j < m; j++) { //j : num No. 
			int c; scanf("%d", &c);
			if (j == 0) { //initial
				Tree[i] = c;
			} else if (c > 0) { //count apples
				if (Tree[i] > c) { //apples lost
					Tree[i] = c;
					Drop[i] = true;
				}
			} else { //take apples
				Tree[i] += c;
			}
		}
	}
	
	//output
	for (int i = 0; i <= N; i++) { // T, D
		T += Tree[i];
		if (Drop[i]) D++;
	}
	for (int i = 0; i <= N-3; i++) { //E
		 (!Drop[i+2]) { //skip 2
			i += 2;
			continue;
		}
		if (Drop[i] && Drop[i+1] && Drop[i+2]) E++;
	}
	if (Drop[N-2] && Drop[N-1] && Drop[0]) E++;	
	if (Drop[N-1] && Drop[0] && Drop[1]) E++;
	printf("%d %d %d\n", T, D, E);
		
	return 0;	
}
