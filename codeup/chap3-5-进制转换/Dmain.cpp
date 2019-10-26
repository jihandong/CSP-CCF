#include<bits/stdc++.h>
using namespace std;

int main() {
	//var
	int N;
	//input
	while((scanf("%d", &N)) > 0) {
		string s = "";
		if(N == 0) s = "0";
		while(N != 0) {
			s += ((N % 8) + '0');
			N /= 8; 
		}
		//output
		for(int i = s.size()-1; i >= 0; i--) {
			printf("%c", s[i]);
		} printf("\n");
	}
	return 0;
}
