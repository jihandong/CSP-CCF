#include<cstdio>
#include<algorithm>
using namespace std;

int N, L, H;
typedef struct student {
	int num;
	int virtue;
	int talent;
	int vnt;
	int type;
	student() {}
	student(int _num, int _virtue, int _talent) {
		num = _num;
		virtue = _virtue;
		talent = _talent;
		vnt = _virtue + _talent;
		if(_virtue >= H && _talent >= H) type = 1;
		else if(_virtue >= H && _talent >= L)	type = 2;
		else if(_virtue >= _talent && _talent >= L) type = 3;
		else if(_virtue >= L && _talent >= L)	type = 4;
		else type = 5;
	}
} Student;

int cmp(Student a, Student b) {
	//审题时尤其要注意边界条件 
	if(a.type != b.type)	return a.type < b.type;
	else if(a.vnt != b.vnt) return a.vnt > b.vnt;
	else if(a.virtue != b.virtue) return a.virtue > b.virtue;
	else return a.num < b.num;
}

int main() {
	scanf("%d%d%d", &N, &L, &H);
	Student S[N];	//可以设置为外部变量，预先声明足够大的空间：100010 
	int n, v, t;
	for(int i = 0; i < N; i++) {
		scanf("%d%d%d", &n, &v, &t);	//&真的容易忘 
		S[i] = student(n, v, t);
	}
	sort(S, S+N, cmp); 
	int count = 0;
	for(; count < N; count++) {
		if(S[count].type == 5) break;
	}
	printf("%d\n", count);
	for(int i = 0; i < count; i++) {
		printf("%d %d %d\n", S[i].num, S[i].virtue, S[i].talent);
	}
	return 0;
}
