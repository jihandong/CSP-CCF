#include<bits/stdc++.h>
using namespace std;

int main() {
	int N;
	while((scanf("%d", &N)) != EOF) {
		//input
		int a2num = 0;
		int a4num = 0;
		double a4 = 0;
		int a1 = 0, a2 = 0, a3 = 0, a5 = 0;
		int num;
		for (int i = 0; i < N; i++) {
			scanf("%d", &num);
			//a1
			if(num % 10 == 0) a1 += num;
			//a2
			if(num % 5 == 1) {
				a2num++; 
				if(a2num % 2) a2 += num;
				else 		  a2 -= num;				
			}
			//a3
			if(num % 5 == 2) a3++;
			//a4
			if(num % 5 == 3) {
				a4 += num;
			    a4num++;
			}
			//a5
			if((num % 5 == 4) && (a5 < num)) a5 = num;
		}
		//a1
		if(a1 == 0) printf("N ");
		else 		printf("%d ", a1);
		//a2
		if(a2num == 0) printf("N ");
		else 		printf("%d ", a2);
		//a3
		if(a3 == 0) printf("N ");
		else 		printf("%d ", a3);
		//a4
		if(a4 == 0) printf("N ");
		else 		printf("%.1f ", a4 / a4num);
		//a5
		if(a5 == 0) printf("N\n");
		else 		printf("%d\n", a5);
	}
	return 0;
}
