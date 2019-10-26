#include<bits/stdc++.h>
using namespace std;

int main() {
	//var
	int M;
	string s[4];
	//input
	scanf("%d%*c", &M);
	for(int i = 0; i < M; i++) {
		getline(cin, s[i % 4]);
		//output
		if(i == 0) {
			printf("1=%s\n", s[0].c_str());
		} else if(i == 1) {
			printf("1=%s 2=%s\n", s[1].c_str(), s[0].c_str());
		} else if(i == 2) {
			printf("1=%s 2=%s 3=%s\n", s[2].c_str(), s[1].c_str(), s[0].c_str());
		} else {
			printf("1=%s 2=%s 3=%s 4=%s\n", s[i%4].c_str(), s[(i+3)%4].c_str(), s[(i+2)%4].c_str(), s[(i+1)%4].c_str());
		}
	}
	return 0;
}
