#include<bits/stdc++.h>
using namespace std;

int main() {
	//var
	string s;
	while(true) {
		if(cin.eof()) break;
		//input
		getline(cin, s);
		//sort
		sort(s.begin(), s.end());
		//output
		printf("%s\n", s.c_str());
	}
	return 0;
}
