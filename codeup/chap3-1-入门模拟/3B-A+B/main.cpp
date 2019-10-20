#include<bits/stdc++.h>
using namespace std;

int main() {
	while(true) {
		//input
		if (cin.eof()) break;
		string str;
		getline(cin, str);
		int mpos = str.find(" ", 0);
		string a = str.substr(0, mpos);
		string b = str.substr(mpos + 1, str.size() - mpos - 1);
		//adjust a and b
		int apos = 0, bpos = 0;
		while((apos = a.find(",", apos)) != string::npos) {
			a.erase(a.begin() + apos);
		}
		while((bpos = b.find(",", bpos)) != string::npos) {
			b.erase(b.begin() + bpos);
		}
		//output
		printf("%d\n", stoi(a) + stoi(b));
	}
	return 0;
}
