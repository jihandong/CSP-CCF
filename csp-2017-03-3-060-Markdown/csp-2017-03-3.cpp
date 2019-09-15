/*
 * 1.审题-输出要求：要求过滤空行，没有注意导致失去……
 * 2.审题-输入要求：要求嵌套解析，没有注意导致失去总计70分
 * 3.正则表达式：使用正则表达式会方便非常多
 * 4.vector的vector：复杂的数据结构换简单的代码
 */
#include<bits/stdc++.h>
using namespace std;

string buf;
vector<string> html;

string a_line(string b) { //analyse bufine
	bool intext = false;
	bool inlink = false;
	int pos = 0;
	string s = "";
	while (pos < b.size()) {
		if (b[pos] == '[') {
			int mpos = b.find("]", pos + 1);
			int bpos = b.find("(", mpos + 1);
			int epos = b.find(")", bpos + 1);
			s += ("<a href=\"" + a_line(b.substr(bpos+1, epos-bpos-1)) + "\">" + a_line(b.substr(pos+1, mpos-pos-1)) + "</a>");
			pos = epos;
		} else if (b[pos] == '_') {
			int epos = b.find("_", pos + 1);
			s += ("<em>" + b.substr(pos+1, epos-pos-1) + "</em>");
			pos = epos;
		} else {
			s += b[pos];
		}
		pos++;
	}
	return s;
}

void i_md() {
	bool inpara = false;
	bool inarray = false;
	while(getline(cin, buf)) {
		if (buf == "") { //blank line
			if (inarray == true) {
				inarray = false;
				html.push_back("</ul>");
			}
			if (inpara == true) {
				inpara = false;
				html[html.size() - 1] += "</p>";
			}
		} else if (buf[0] == '#') { // titile
			int c = 0;
			while(buf[c] == '#') c++;
			string head = "<h"; head += (c + '0'); head += ">";
			string tail = "</h"; tail += (c + '0'); tail += ">";
			while(buf[c] == ' ') c++; //rm blank
			buf = buf.substr(c, buf.size() - c);
			html.push_back(head + a_line(buf) + tail);
		} else if (buf[0] == '*') { // array
			if (inarray == false) {
				inarray = true;
				html.push_back("<ul>");
			}
			int c = 1;
			while(buf[c] == ' ') c++; //rm blank
			buf = buf.substr(c, buf.size() - c);
			html.push_back("<li>" + a_line(buf) + "</li>");
		} else { // para
			if (inpara == false) {
				inpara = true;
				html.push_back("<p>" + a_line(buf));
			} else
				html.push_back(a_line(buf));
		}
	}
	if (inarray == true)
		html.push_back("</ul>");
	if (inpara == true)
		html[html.size() - 1] += "</p>";
}

void o_html() {
	for(int i = 0; i < html.size(); i++)
		printf("%s\n", html[i].c_str());
}

int main() {
	i_md();
	o_html();
	return 0;
} 
