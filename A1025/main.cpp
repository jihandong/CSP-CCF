#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;

struct student {
	char id[15];
	int grade, rank, court, crank;
} S[30010];
int C[110] = {0, };
int N;

int cmp(struct student a, struct student b) {
	//又没有注意题目中要求字符串递增排列的条件 
	if(a.grade == b.grade) return strcmp(a.id, b.id) < 0;
	else return a.grade > b.grade;
}

int main() {
	scanf("%d", &N);
	int bias = 0;
	for(int i = 1; i <= N; i++) {
		scanf("%d", C + i);
		for(int j = 0; j < C[i]; j++) {
			scanf("%s%d", &S[j+bias].id, &S[j+bias].grade); //&很容易遗漏 
		}
		C[i] += C[i-1];
		bias = C[i];
	} 
	for(int i = 0; i < N; i++) {
		sort(S + C[i], S + C[i+1], cmp);
		int prank = 1, pgrade = 101;
		for(int j = C[i]; j < C[i+1]; j++) {
			S[j].court = i + 1;
			if(pgrade == S[j].grade) {
				S[j].crank = prank;
			}
			else {
				S[j].crank = j - C[i] + 1;
				prank = j - C[i] + 1;
				pgrade = S[j].grade;
			}
		}
	}
	//大排序可以和输出合并到一起的，没有必要额外设立一个rank项目 
	sort(S, S + C[N], cmp);
	int prank = 1, pgrade = 101;
	for(int i = 0; i < C[N]; i++) {
		if(pgrade == S[i].grade) {
			S[i].rank = prank;
		}
		else {
			S[i].rank = i + 1;
			prank = i + 1;
			pgrade = S[i].grade;
		}
	}
	printf("%d\n", C[N]);
	for(int i = 0; i < C[N]; i++) {
		printf("%s %d %d %d\n", S[i].id, S[i].rank, S[i].court, S[i].crank);
	}
	return 0;
}
