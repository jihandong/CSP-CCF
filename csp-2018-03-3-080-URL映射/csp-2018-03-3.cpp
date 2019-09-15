#include<bits/stdc++.h>
using namespace std;

int n, m;
struct url {
	string name;
	vector<string> path;
	int type;
};
struct url rules[100];
struct url addr;
queue<string> buf;

void i_rule(int r) {
	string s;
	getline(cin, s);
	int bpos = 1;
	int epos;
	int mpos = s.find(" ", 0);
	rules[r].name = s.substr(mpos + 1, s.size() - mpos - 1);
	while ((epos = s.find("/", bpos)) != string::npos) {
		rules[r].path.push_back(s.substr(bpos, epos - bpos));
		bpos = epos + 1; 
	}
	if (bpos == mpos) {
		rules[r].type = 0; //path
	} else {
		rules[r].path.push_back(s.substr(bpos, mpos - bpos));
		if (rules[r].path.back() == "<path>")
			rules[r].type = 10; //<path>
		else
			rules[r].type = 1; //file	
	}
}

void i_addr() {
	addr.path.clear();
	
	string s;
	getline(cin, s);
	int bpos = 1;
	int epos;
	while ((epos = s.find("/", bpos)) != string::npos) {
		addr.path.push_back(s.substr(bpos, epos - bpos));
		bpos = epos + 1; 
	}
	if (bpos == s.size()) {
		addr.type = 0; //path
	} else {
		addr.type = 1; //file
		addr.path.push_back(s.substr(bpos, s.size() - bpos));
	}
}

bool a_match(int r) {
	queue<string> empty;
	swap(buf, empty);

	int rtype = rules[r].type, atype = addr.type;
	int rlen = rules[r].path.size(), alen = addr.path.size();
	
	if (rtype + atype == 1) return false;
	if (rtype != 10 && rlen != alen) return false;

	for (int i = 0; i < rlen; i++) {
		string rnode = (rules[r].path)[i];
		string anode = (addr.path)[i];
		if (rnode == "<int>") {
			bool zero = true;
			int zpos = 0;
			for (int j = 0; j < anode.size(); j++) {
				if (zero && anode[j] == '0')
					zpos++;
				else
					zero = false;
				if (anode[j] < '0' || anode[j] > '9')
					return false;
			}
			buf.push(anode.substr(zpos, alen - zpos)); continue;
		} else if (rnode == "<str>") {
			buf.push(anode); continue;
		} else if (rnode == "<path>") {
			for (int j = i + 1; j < alen; j++) {
				anode += "/";
				anode += (addr.path)[j];
			}
			if (addr.type == 0)
				anode += "/";
			buf.push(anode); break;
		} else if (anode == rnode) {
			continue;
		} else {
			return false;
		}
	}
	return true;
}

void o_print(int r) {
	printf("%s", rules[r].name.c_str());
	while(!buf.empty()) {
		printf(" %s", buf.front().c_str());
		buf.pop();
	}
	printf("\n");
}

int main() {
	//input
	scanf("%d%d%*c", &n, &m);
	for (int i = 0; i < n; i++) {
		i_rule(i);
	}

	for (int i = 0; i < m; i++) {
		i_addr(); //input
		int flag = -1;
		for (int j = 0; j < n; j++) {
			if (a_match(j)) { //analysis
				flag = j; break;
			} 
		}
		if (flag >= 0) //output
			o_print(flag);
		else
			printf("404\n");
	}
	
	return 0;
}
