#include<bits/stdc++.h>
using namespace std;

stack<char> op;
set<char> st {'(', ')', '[', ']', '{', '}'};
map<char,char> mp {
	{ '}', '{' },
	{ ']', '[' },
	{ ')', '(' }
};

bool record(char c) {
	bool flag;
	if(st.find(c) == st.end()) { //not in st
		flag = true;
	} else {
		if(op.empty()) { //empty stack
			if(mp.find(c) != mp.end()) { //no match
				flag = false;
			} else { //wait for match
				op.push(c);
				flag = true;
			}
		} else { //not empty
			if(mp.find(c) != mp.end() && mp[c] == op.top()) { //good match
				op.pop();
				flag = true;
			} else if(mp.find(c) != mp.end()) { //bad match
				flag = false;
			} else { //wait for match
				op.push(c);
				flag = true;
			}
		}	
	}
	return flag;
}

void clear_stack(stack<char> &s) {
	stack<char> tmp;
	swap(tmp, s);
}

int main() {
	//var
	int N;
	while((scanf("%d%*c", &N)) == 1) {
		//input
		for(int i = 0; i < N; i++) {
			//initial
			clear_stack(op);
			string s;
			getline(cin, s);
			bool flag = true;
			//check
			for(int j = 0; j < s.size(); j++) {
				flag = record(s[j]);
				if(!flag) break;
			}
			//output result
			if(flag && op.empty()) {
				printf("yes\n");
			} else {
				printf("no\n");
			}
		}
	}	
	return 0;
} 
