#include<bits/stdc++.h>
using namespace std;

map<string,set<string> > mp;
struct task{
	string name;
	task() {}
	task(string _name) {
		this->name = _name;
	}
	friend bool operator < (task t1, task t2) {
		if (mp.find(t2.name) != mp.end() && mp[t2.name].find(t1.name) != mp[t2.name].end())
			return true;
		else
			return t1.name > t2.name;
	}
};
priority_queue<task> pq;

int main() {
	//var
	int N;
	while((scanf("%d%*c", &N)) == 1) {
		//corner
		if(N == 0) continue;
		//inital
		mp.clear();
		//pq.clear();
		//input
		for(int i = 0; i < N; i++) {
			string s;
			getline(cin, s);
			for(int j = 0; j < s.size(); j++) {
				if(s[j] == '(' || s[j] == ')' || s[j] == ',')
					s[j] = ' ';
			}
			int pos1 = 0, pos2;
			while((pos2 = s.find(" ", pos1)) != string::npos) {
				if(pos1 == 0) {	//task name
					string name = s.substr(0, pos2);
					set<string> st;
					mp[name] = st;
				} else { //after tasks
					string name = s.substr(pos1, pos2-pos1);
					if(name != "NULL") mp[name].insert(name);
				}
				pos1 = pos2+1;
			}
		}
		//push
		for(map<string,set<string> >::iterator it = mp.begin(); it != mp.end(); it++) {
			pq.push(task(it->first));
		}
		//output
		while(!pq.empty()) {
			printf("%s", (pq.top()).name.c_str());
			pq.pop();
			if(!pq.empty()) printf(" ");
		}	printf("\n");
	}
	return 0;
}

