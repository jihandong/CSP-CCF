#include<bits/stdc++.h>
using namespace std;

const int MAXM = 51;
const int MAXN = 30001;
int K, KI[MAXM], KS;
int C, CI[MAXM];
struct good{
	int type;
	int id;
	int score;
	good() {}
	good(int t, int i, int s) {
		this->type = t;
		this->id = i;
		this->score = s;
	}
	friend bool operator < (good g1, good g2) {
		if(g1.score != g2.score) {
			return g1.score > g2.score;
		} else if(g1.type != g2.type) {
			return g1.type < g2.type;
		} else {
			return g1.id < g2.id;
		}
	}
};
set<good> Sti;
set<int> Sto[MAXM];

void test() {
	for(set<good>::iterator it = Sti.begin(); it != Sti.end(); it++) {
		printf("\t%d %d %d\n", it->score, it->type, it->id);
	}
}

int main() {
	//var
	int M, N, OPn; 
	//input goods
	scanf("%d%d", &M, &N);
	for(int i = 0; i < N; i++) {
		int id, score;
		scanf("%d%d", &id, &score);
		for(int j = 0; j < M; j++) { 
			Sti.insert(good(j, id, score));
		}
	}
	//commands
	scanf("%d", &OPn);
	for(int i = 0; i < OPn; i++) {
		//var
		int cmd, type, id, score;
		scanf("%d", &cmd);
		switch(cmd) {
			case 1://add
				scanf("%d%d%d", &type, &id, &score);
				//delete old
				for(set<good>::iterator it = Sti.begin(); it != Sti.end(); it++) {
					if(it->type == type && it->id == id) {
						Sti.erase(it);	
						break;
					}
				}
				Sti.insert(good(type, id, score));
				break;
			case 2://delete
				scanf("%d%d", &type, &id);
				for(set<good>::iterator it = Sti.begin(); it != Sti.end(); it++) {
					if(it->type == type && it->id == id) {
						Sti.erase(it);	
						break;
					}
				}
				break;
			case 3://search
				C = 0;							//clear
				fill(CI, CI+M, 0);				//clear
				for(int j = 0; j < M; j++) {	//clear
					Sto[j].clear();
				}
				//input needs
				scanf("%d", &K);
				KS = 0;
				for(int j = 0; j < M; j++) {
					scanf("%d", KI+j);
					KS += KI[j];
				}
				//choose good
				for(set<good>::iterator it = Sti.begin(); it != Sti.end(); it++) {
					if(C == K || C == KS) break;
					if(CI[it->type] < KI[it->type]) {
						Sto[it->type].insert(it->id);
						C++; CI[it->type]++;	
					}
				}
				//output chosen goods
				for(int j = 0; j < M; j++) {
					if(Sto[j].size() == 0) {
						printf("-1\n");
						continue;
					}
					for(set<int>::iterator it = Sto[j].begin(); it != Sto[j].end(); it++) {
						if(it != Sto[j].begin()) printf(" ");
						printf("%d", *it);
					}	printf("\n");
				}
				break;
		}
	}
	return 0;
}
