/* 元素选择器：80
 * 1.下标溢出：输入并不总是合法，如果不加上错误处理可能会导致溢出，50->70
 * 2.审题：大小写等效或者不等效，结果不同,70->80
 */
#include<bits/stdc++.h>
using namespace std;

int n, m;
struct ele{
	string name;
	string feature;
	int father;
} html[101];

string alower(string s) {
	string result = "";
	for(int i = 0; i < s.size(); i++) {
		if (s[i] >= 'A' && s[i] <= 'Z') result += (s[i] + 'a' - 'A'); 
		else result += s[i];
	}
	return result;
}

void input() {
	scanf("%d%d%*c", &n, &m);
	int fpos = -1;
	for (int i = 0; i < n; i++) {
		string s;
		getline(cin, s);
		// get feature
		int mpos = s.find("#", 0);
		if (mpos != string::npos) {
			html[i].feature = s.substr(mpos, s.size() - mpos);
			s = s.substr(0, mpos - 1);
		}
		// get name
		int bpos = 0, epos;
		while((epos = s.find("..", bpos)) != string::npos) bpos = epos + 2;
		html[i].name = alower(s.substr(bpos, s.size() - bpos));
		// get layer
		if (fpos < bpos) {
			html[i].father = i - 1;
		} else if (fpos == bpos) {
			html[i].father = html[i-1].father;
		} else {
			int bt = (fpos - bpos) / 2 + 1;
			int f = i - 1;
			while(bt--) f = html[f].father;
			html[i].father = f;
		}
		// next
		fpos = bpos;
	}
}

void output() {
	while(m--) {
		vector<string> sl;
		string s;
		getline(cin, s); s += " ";
		int bpos = 0, epos;
		while((epos = s.find(" ", bpos)) != string::npos) {
			if (s[bpos] != '#') sl.push_back(alower(s.substr(bpos, epos - bpos)));
			else sl.push_back(s.substr(bpos, epos - bpos));
			bpos = epos + 1;
		}
		// match
		vector<int> ln;
		for (int i = 0; i < n; i++) { //try each element
			bool flag = true;
			for (int j = 0; j < sl.size(); j++) {
				int k = sl.size() - j - 1;
				int f = i, c = j;
				while(c-- && f != -1) f = html[f].father;
				if (f == -1) {
					flag = false; break;
				}
				if (sl[k] != (sl[k][0] == '#' ? html[f].feature : html[f].name)) {
					flag = false; break;
				}
			}
			if (flag) ln.push_back(i+1);
		}
		// printf
		printf("%d", ln.size());
		for (int i = 0; i < ln.size(); i++)
			printf(" %d", ln[i]);
		printf("\n");
	}
}

/*
void test1() {
	for(int i = 0; i < n; i++) {
		printf("%d %s %s\n", html[i].father, html[i].name.c_str(), html[i].feature.c_str());
	}
}*/

int main() {
	input();
	output();
	return 0;
}
