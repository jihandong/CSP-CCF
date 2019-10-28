#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1001;
const int MAXM = 11;
int Points[MAXM];
struct Student {
	string name;
	int grade;
	Student() {}
	Student(string _name, int _grade) {
		this->name = _name;
		this->grade = _grade;
	}
} Stu[MAXN];

bool cmp(Student s1, Student s2) {
	if(s1.grade != s2.grade) {
		return s1.grade > s2.grade;
	} else {
		return s1.name < s2.name;
	}
}


int main() {
	//var
	int N, M, P;
	//input
	while((scanf("%d", &N)) > 0) {
		//break
		if(N == 0) break;
		scanf("%d%d", &M, &P);
		//input points
		for(int i = 0; i < M; i++) {
			scanf("%d", &Points[i]);
		}
		//input student grade
		scanf("%*c");
		for(int i = 0; i < N; i++) {
			string s; cin >> s;
			int S; scanf("%d", &S);
			int sum = 0;
			for(int j = 0; j < S; j++) {
				int tmp; scanf("%d", &tmp);
				sum += Points[tmp-1];
			}
			Stu[i] = Student(s, sum);
		}
		//sort
		sort(Stu, Stu+N, cmp);
		//count
		int cnt = 0;
		for(int i = 0; i < N; i++) {
			if(Stu[i].grade >= P) cnt++;
		}
		//output
		printf("%d\n", cnt);
		for(int i = 0; i < N; i++) {
			printf("%s %d\n", Stu[i].name.c_str(), Stu[i].grade);
		}
	}
	return 0;
}
