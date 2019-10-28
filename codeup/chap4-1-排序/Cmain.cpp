#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100001;
struct Student {
	int id;
	string name;
	int grade;
	Student() {}
	Student(int _id, string _name, int _grade) {
		this->id = _id;
		this->name = _name;
		this->grade = _grade;
	}
} Stu[MAXN];

bool cmp1(Student s1, Student s2) {
	return s1.id < s2.id;
}
bool cmp2(Student s1, Student s2) {
	if(s1.name != s2.name)
		return s1.name < s2.name;
	else
		return s1.id < s2.id;
}
bool cmp3(Student s1, Student s2) {
	if(s1.grade != s2.grade)
		return s1.grade < s2.grade;
	else
		return s1.id < s2.id;
}

int main() {
	//var
	int N, C, cnt = 0;
	//input
	while((scanf("%d%d%*c", &N, &C)) > 0) {
		if(N == 0) break;
		cnt++;
		for(int i = 0; i < N; i++) {
			string s;
			getline(cin, s);
			int pos1 = s.find(" ", 0);
			int pos2 = s.find(" ", pos1+1);
			Stu[i] = Student(
				stoi(s.substr(0, pos1)),
				s.substr(pos1+1, pos2-1-pos1), 
				stoi(s.substr(pos2+1, s.size()-1-pos2))
			);
		}
		//sort
		switch(C) {
			case 1: sort(Stu, Stu+N, cmp1); break;
			case 2: sort(Stu, Stu+N, cmp2); break;
			case 3: sort(Stu, Stu+N, cmp3); break;
			default: break;
		}
		//output
		printf("Case %d:\n", cnt);
		for(int i = 0; i < N; i++) {
			printf("%06d %s %d\n", Stu[i].id, Stu[i].name.c_str(), Stu[i].grade);
		}
	}
	return 0;
}
