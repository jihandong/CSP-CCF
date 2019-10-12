/* json查询：60
 * 1.解析有层次的表达式：使用栈的原理
 * 2.输入输出：可以使用map容器不断添加映射
 * 3.SICP写法：可行，要有自己的风格，自己的习惯
 */

#include<bits/stdc++.h>
using namespace std;

int n, m;
map<string, string> kv;
string json = "";
string buf;
vector<string> path;

int a_string(int pos) {
	buf = ""; pos++;
	while(true) {
		if (json[pos] == '\\') {
			buf += json[pos + 1];
			pos++;
		} else if (json[pos] != '\"') {
			buf += json[pos];
		} else {
			break;
		}
		pos++;
	}
	return pos + 1;
}

void i_json() {
	//get the whole json
	for (int i = 0; i < n; i++) { 
		string tmp; 
		getline(cin, tmp);
		json += tmp;
	}
	//parse into tree
	int pos = 1;
	path.push_back("");
	while(pos < json.size()) { //accept an key-value each turn
		string key, value;
		while(json[pos] != '\"') pos++; //rm blank
		// prapare prefix
		string prefix = "";
		for (int i = 0; i < path.size(); i++) {
			prefix += path[i];
			if (i != 0) prefix += ".";
		}
		// get key
		pos = a_string(pos);
		key = buf;
		// get value
		while(json[pos] == ' ' || json[pos] == ':') pos++;
		if (json[pos] == '\"') {
			pos = a_string(pos);
			value = buf;
		} else if (json[pos] == '{') {
			path.push_back(key);
			value = "";
		}
		// key-value
		kv[prefix + key] = value;
		// next
		while (json[pos] != '\"') {
			if (json[pos] == '}')
				path.pop_back();
			pos++;
		}
	}
}

void o_find() {
	string s;
	for (int i = 0; i < m; i++) {
		getline(cin, s);
		map<string,string>::iterator it = kv.find(s);
		if (it == kv.end()) {
			printf("NOTEXIST\n");
		} else if (it->second == "") {
			printf("OBJECT\n");
		} else {
			printf("STRING %s\n", (it->second).c_str());
		}
	}
}

/*void test() {
	printf("\n");
	for(map<string,string>::iterator it = kv.begin(); it != kv.end(); it++) {
		printf("%s\t%s\n", (it->first).c_str(), (it->second).c_str());
	}
	printf("\n");
}*/

int main() {
	scanf("%d%d%*c", &n, &m);
	i_json();
	
	//test();
	
	o_find();
	return 0;
}
