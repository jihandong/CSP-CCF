#include<bits/stdc++.h>
using namespace std;

int Num[10];

int main() {
	//input
	while((scanf("%d%d%d%d%d%d%d%d%d%d", Num, Num+1, Num+2, Num+3, Num+4, Num+5, Num+6, Num+7, Num+8, Num+9)) == 10) {
		//swap min
		int min_id = 0, min_val = Num[0];
		for(int i = 1; i < 10; i++) {
			if(Num[i] < min_val) {
				min_val = Num[i];
				min_id = i;
			}
		}	swap(Num[0], Num[min_id]);
		//swap max
		int max_id = 0, max_val = Num[0];
		for(int i = 1; i < 10; i++) {
			if(Num[i] > max_val) {
				max_val = Num[i];
				max_id = i;
			}
		} 	swap(Num[9], Num[max_id]);
		//output
		for(int i = 0; i < 10; i++) {
			printf("%d ", Num[i]);	
		}	printf("\n");
	}
	return 0;
}
