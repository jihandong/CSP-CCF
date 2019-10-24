#include<bits/stdc++.h>
using namespace std;

//              1	2	3	4	5	6	7	8	9	10	11	12
int M[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
	//var 
	int N;
	scanf("%d", &N);
	for(int i = 0; i < N; i++) {
		int y, m, d;
		scanf("%d%d%d", &y, &m, &d);
		d++;
		//add month
		if(d > M[m]) {
			d = 1;
			m++;
		}
		//add year
		if(m > 12) {
			m = 1;
			y++;
		} 
		//output
		printf("%04d-%02d-%02d\n", y, m, d);
	}
	return 0; 
}
