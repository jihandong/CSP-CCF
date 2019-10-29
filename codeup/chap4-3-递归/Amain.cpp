#include<bits/stdc++.h>
using namespace std;

const int MAXN = 21;
int Way[MAXN]; 
int Wtop;

int count(int n) {
	while(Wtop <= n) {
		Way[Wtop] = Way[Wtop-1] + Way[Wtop-2];
		Wtop++;
	}
	return Way[n];
}

int main() {
	//var
	int N;
	//initial
	Way[1] = 1; Way[2] = 2; Wtop = 3;
	//input
	while((scanf("%d", &N)) > 0) {
		printf("%d\n", count(N));
	}
	return 0;
}
