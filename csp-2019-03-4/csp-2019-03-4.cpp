#include<bits/stdc++.h>
using namespace std;

typedef pair<char, int> command;
int T, n;
queue<command> C[1010]; //great idea! implement tomorrow 

void clear(queue<command>& q) {
	queue<command> empty;
	swap(q, empty);
}

int main() {
	scanf("%d%d%*c", &T, &n);
	while (T--) {
		// 1. input
		string s;
		for (int i = 0; i < n; i++) {
			getline(cin, s);
			s += " ";
			int pos = 0, next;
			while ((next = s.find(" ", pos)) != string::npos) {
				command cmd;
				cmd.first = *(s.begin() + pos);
				cmd.second = atoi(s.substr(pos + 1, next).c_str());
				C[i].push(cmd);
				pos = next + 1;
			}
		}
		// 2. analysis output
		bool dead_lock = false;
		int empty_queues = 0;
		while (!dead_lock) {
			dead_lock = true; // reset dead_lock check
			empty_queues = 0; // rest empty_queues count
			for (int i = 0; i < n; i++) {
				if (C[i].empty()) {
					empty_queues++;
					continue;
				}
				command cmd1 = C[i].front();
				command cmd2 = C[cmd1.second].front();
				if (cmd2.second == i && (cmd1.first + cmd2.first == 'S' + 'R')) {
					C[i].pop();
					C[cmd1.second].pop();
					dead_lock = false;
				} 
			}
		}
		if (empty_queues == n)
			printf("0\n"); // no dead lock
		else 
			printf("1\n"); // is a dead lock
		// 3. reset queues
		for (int i = 0; i < n; i++)
			clear(C[i]);
	} 
	return 0;
}
