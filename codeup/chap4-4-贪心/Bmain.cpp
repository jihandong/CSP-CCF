#include<bits/stdc++.h>
using namespace std;

int main() {
	//var
	int N;
	while((scanf("%d", &N)) > 0) {
		if(N == 0) break;
		int m1 = 0;
		double m2 = 0;
		if(N <= 4) {
			m1 = 10;
		} else if(N <= 8) {
			m1 = 10 + 2*(N - 4);
		} else {
			//divide 8
			m1 = ((N/8) * 18);
			//else
			N %= 8;
			if(N < 5) {
				m2 = (2.4*N);
			} else {
				m1 += (10 + 2*(N - 4)); 
			}
		}
		//output
		if(m2 < 0.1) {	
			printf("%d\n", m1);
		} else {
			printf("%.1f\n", m1+m2);
		}
	} 
	return 0;
}
