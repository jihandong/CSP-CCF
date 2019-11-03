#include<bits/stdc++.h>
using namespace std;

map<string,int> mp;

int main() {
	while(true) {
		if(cin.eof()) break;
		//initial
		mp.clear();
		//input
		string s, w = "";
		getline(cin, s);
		if(s == "") continue;
		//analysis
		s += ' '; 
		for(int i = 0; i < s.size(); i++) {
			if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
				w += s[i];
			} else if(s[i] >= 'A' && s[i] <= 'Z') {
				w += (s[i] + 'a' - 'A');
			} else { //add word
				if(w != "") {
					if(mp.find(w) == mp.end()) {
						mp[w] = 0;
					}	mp[w]++;
				}
				w = "";
			}
		}
		//find bigest
		map<string,int>::iterator maxit = mp.begin();
		for(map<string,int>::iterator it = mp.begin(); it != mp.end(); it++) {
			if(it->second > maxit->second) {
				maxit = it;
			}
		}
		//output
		printf("%s %d\n", (maxit->first).c_str(), maxit->second);
	}
	return 0;
} 
