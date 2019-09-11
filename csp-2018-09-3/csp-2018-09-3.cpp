/*
 * ≤‚ ‘ 
 */
#include<bits/stdc++.h>
using namespace std;

int n, m;
struct node {
	string name;
	string feat;
	int father;
} nodes[100];

void new_vs(vector<string>& q) {
	vector<string> empty;
	swap(q, empty);
}

int main() {
	// input
	scanf("%d%d%*c", &n, &m);
	string s;
	int prelayer = -1;
	for (int i = 0; i < n; i++) {
		getline(cin, s);
		int pos = 0, layer = 0, namepos= 0, featpos;
		// count layer
		while ((pos = s.find("..", pos)) != string::npos) {
			pos += 2;
			namepos = pos;
			layer++;
		}
		if (prelayer == -1) {
			nodes[i].father = -1;
		} else if (layer > prelayer) {
			nodes[i].father = i - 1;
		} else if (layer == prelayer) {
			nodes[i].father = nodes[i - 1].father;
		} else {
			int fa = i - 1;
			int back = prelayer - layer + 1;
			while (back--)
				fa = nodes[fa].father;
			nodes[i].father = fa;
		}
		prelayer = layer;
		// add name and feature
		if ((pos = s.find(" ", namepos)) != string::npos) {
			int featpos = pos + 1;
			nodes[i].name = s.substr(namepos, pos - namepos);
			nodes[i].feat = s.substr(featpos, s.length() - featpos);
		} else {
			nodes[i].name = s.substr(namepos, s.length() - namepos);
		}
	}
	
	//output
	for (int i = 0; i < m; i++) {
		int count = 0;
		int lines[100];
		string s;
		int top = 0;
		getline(cin, s);
		s += " ";
		int prepos = 0, pos;
		while ((pos = s.find(" ", prepos)) != string::npos) {
			selectors[top++] = s.substr(prepos, pos - prepos);
			prepos = pos + 1;
		}
		
		// test selector
		printf("test selector:");
		for (int j = 0; j < top; j++) {
			printf(" %s", selectors[j].c_str());
		}
		printf("\n");
		
		for (int j = 0; j < n; j++) {
			int k = top;
			int now = j;
			bool match = true;
			while(k--) {
				if (now < 0) {
					match = false;
					break;
				}
				if (selectors[k][0] == '#' && selectors[k] == nodes[now].name) {
					continue;
				} else if (selectors[k] == nodes[now].feat) {
					continue;
				} else {
					match = false;
					break;					
				}
				now = nodes[now].father;
			}
			if (match) {
				lines[count++] = j + 1;
			}
		}
		
		printf("%d", count);
		for (int j = 0; j < count; j++)
			printf(" %d", lines[j]);
		printf("\n");
	}
	
	return 0;
}
