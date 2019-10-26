#include<bits/stdc++.h>
using namespace std;

bool equal(char c1, char c2) {
	if(c1 >= 'a' && c1 <= 'z') c1 += ('A' - 'a');
	if(c2 >= 'a' && c2 <= 'z') c2 += ('A' - 'a');
	return c1 == c2;
}

int main() {
	//car
	string cut, s;
	getline(cin, cut);
	//input
	while(true) {
		if(cin.eof()) break;
		getline(cin, s);
		//cut substr
		for(int i = 0; i < s.size();) {
			int pos = 0;
			while(pos < cut.size() && i+pos < s.size() && equal(s[i+pos], cut[pos])) {
				pos++;
			}
			if(pos == cut.size()) {
				s.erase(i, pos);
			} else {
				i++;
			}
		}
		//cut blank
		for(int i = 0; i < s.size();) {
			if(s[i] == ' ')
				s.erase(s.begin() + i);
			else
				i++;
		}
		//output
		printf("%s\n", s.c_str());
	}
	return 0;
} 
