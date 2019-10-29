#include<bits/stdc++.h>
using namespace std;

bool Sub[200];

int main() {
	while(true) {
		if(cin.eof()) break;
		//initial
		fill(Sub, Sub+200, false);
		//input
		string s1, s2;
		getline(cin, s1);
		getline(cin, s2);
		//scan s2
		for(int i = 0; i < s2.size(); i++) {
			Sub[s2[i]] = true;
		}
		//output s1
		for(int i = 0; i < s1.size(); i++) {
			if(!Sub[s1[i]])
				printf("%c", s1[i]);
		}	printf("\n");
	}
	return 0;
}

