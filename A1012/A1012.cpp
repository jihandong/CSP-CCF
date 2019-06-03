#include<cstdio>
#include<algorithm>
using namespace std;

struct student { //可以使用一个数组保存成绩，排名只存储一个，4次排序根据优先级可以有机会改变排名 
	int num, Cg, Mg, Eg, Ag, Cr, Mr, Er, Ar, r;
	char s;
	student() {}
	student(int _num, int _Cg, int _Mg, int _Eg) {
		num = _num;
		Cg = _Cg;
		Mg = _Mg;
		Eg = _Eg;
		Ag = (_Cg + _Mg + _Eg) / 3;
	}
} S[2010];
int N, M;
int SS[2010];
int cmpc(struct student a, struct student b) { return a.Cg > b.Cg;} 
int cmpm(struct student a, struct student b) { return a.Mg > b.Mg;}
int cmpe(struct student a, struct student b) { return a.Eg > b.Eg;}
int cmpa(struct student a, struct student b) { return a.Ag > b.Ag;}

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 0; i < N; i++) {
		int n, c, m, e;
		scanf("%d%d%d%d", &n, &c, &m, &e);
		S[i] = student(n, c, m, e);
	}
	for(int i = 0; i < M; i++) scanf("%d", &SS[i]);
	
	sort(S, S + N, cmpc);
	for(int i = 0; i < N; i++) S[i].Cr = i + 1;
	sort(S, S + N, cmpm);
	for(int i = 0; i < N; i++) S[i].Mr = i + 1;
	sort(S, S + N, cmpe);
	for(int i = 0; i < N; i++) S[i].Er = i + 1;
	sort(S, S + N, cmpa);
	for(int i = 0; i < N; i++) S[i].Ar = i + 1;
	
	for(int i = 0; i < N; i++) {
		S[i].r = S[i].Er, S[i].s = 'E';
		if(S[i].r >= S[i].Mr)	{
			S[i].r = S[i].Mr;
			S[i].s = 'M';
		}
		if(S[i].r >= S[i].Cr) {
			S[i].r = S[i].Cr;
			S[i].s = 'C';
		}
		if(S[i].r >= S[i].Ar) {
			S[i].r = S[i].Ar;
			S[i].s = 'A';
		}
	}
	
	for(int i = 0; i < M; i++) {
		bool flag = false;
		for(int j = 0; j < N; j++) {
			if(S[j].num == SS[i]) {
				flag = true;
				printf("%d %c\n", S[j].r, S[j].s);
			}
		}
		if(!flag) printf("N/A\n");
	}
	return 0;
}
