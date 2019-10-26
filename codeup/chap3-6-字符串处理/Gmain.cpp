#include<bits/stdc++.h>
using namespace std;

int main() {
	//var
	int N;
	string s;
	//input
	scanf("%d%*c", &N);
	for(int i = 0; i < N; i++) {
		getline(cin, s);
		int pos = s.find(" ", 0);
		int len1 = pos;
		int len2 = s.size() - pos - 1;
		//output
		if(len1 > len2) {
			printf("%s is longer than %s\n", s.substr(0, pos).c_str(), s.substr(pos+1, s.size()-pos-1).c_str());
		} else if(len1 == len2) {
			printf("%s is equal long to %s\n", s.substr(0, pos).c_str(), s.substr(pos+1, s.size()-pos-1).c_str());
		} else {
			printf("%s is shorter than %s\n", s.substr(0, pos).c_str(), s.substr(pos+1, s.size()-pos-1).c_str());
		}
	}
	return 0;
}
