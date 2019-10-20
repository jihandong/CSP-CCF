#include<bits/stdc++.h>
using namespace std;

int n;

int main() {
	while((scanf("%d", &n)) > 0) {
		int even = 0, odd = 0;
		//input and count
		for(int i = 0; i < n; i++) {
			int num = 0;
			scanf("%d", &num);
			if(num % 2 == 0) {
				even++;
			} else {
				odd++;
			}
		}
		//compare and output
		if(even > odd) {
			printf("NO\n");
		} else {
			printf("YES\n");
		}
	}
	return 0;
} 
