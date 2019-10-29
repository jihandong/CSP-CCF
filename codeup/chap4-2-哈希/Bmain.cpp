#include<bits/stdc++.h>
using namespace std;

const int MAXN = 101;
int BufN[MAXN];
int BufG[MAXN];
map<int,int> Gmp;
map<int,int> Nmp;
int Gtop, Ntop;
int Cnt[MAXN][MAXN];

int main() {
	//vat
	int M, N;
	scanf("%d", &M);
	for(int i = 0; i < M; i++) {
		//initial
		scanf("%d", &N);
		fill(BufG, BufG+N, 0);
		fill(BufN, BufN+N, 0);
		Gmp.clear(); Gtop = 0;
		Nmp.clear(); Ntop = 0;
		fill(Cnt[0], Cnt[0]+MAXN*MAXN, 0);
		//input
		for(int i = 0; i < N; i++) {
			scanf("%d", BufN + i);
		}
		for(int i = 0; i < N; i++) {
			scanf("%d", BufG + i);
		}
		//check and count
		for(int i = 0; i < N; i++) {
			if(Gmp.find(BufG[i]) == Gmp.end()) { //new Group
				Gmp[BufG[i]] = Gtop;
				Gtop++;
			}
			if(Nmp.find(BufN[i]) == Nmp.end()) { //new Num
				Nmp[BufN[i]] = Ntop;
				Ntop++;
			}
			Cnt[Gmp[BufG[i]]][Nmp[BufN[i]]]++; //add
		}
		//output
		for(map<int,int>::iterator i = Gmp.begin(); i != Gmp.end(); i++) { //each group
			printf("%d={", i->first);
			for(map<int,int>::iterator j = Nmp.begin(); j != Nmp.end(); j++) { //each num
				if(j != Nmp.begin())
					printf(",");
				printf("%d=%d", j->first, Cnt[Gmp[i->first]][Nmp[j->first]]);
			}
			printf("}\n");
		}
	}
	return 0;
}
