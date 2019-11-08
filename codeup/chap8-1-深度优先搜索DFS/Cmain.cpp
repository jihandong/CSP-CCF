#include<bits/stdc++.h>
using namespace std;

const int MAXN = 30; 
int Num[MAXN];
int N, R;

bool isPrime(int s) {
	if(s <= 3) {
		return s > 1;	
	} else if(s%6 != 5 && s%6 != 1) {
		return false;
	} else {
		int sq = sqrt(s);
		for(int i = 5; i <= sq; i += 6) {
			if(s%i == 0 || s%(i+2) == 0) {
				return false;
			}
		}
		return true;
	}
}

int permutation(int s, int r, int n) {
	if (r == R) {	//leave node
		//printf("%d", s);
		//if(isPrime(s)) printf("+");
		//printf("\n");
		return isPrime(s)? 1 : 0;
	} else if(n == N) {	//out of range 
		return 0;
	} else if(r + N - n < R) { //cut branch
		return 0;
	} else { //branch
		int s1 = s + Num[n];
		return permutation(s1, r+1, n+1) + permutation(s, r, n+1);
	}
}

int main() {
	while((scanf("%d%d", &N, &R)) == 2) {
		for(int i = 0; i < N; i++) {
			scanf("%d", Num+i);
		}
		printf("%d\n", permutation(0, 0, 0));
	}
	return 0;
}
