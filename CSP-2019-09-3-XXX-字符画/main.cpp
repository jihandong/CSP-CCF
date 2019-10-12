///////////////////////////////////////////////////////////////////////
//	csp-2019-09-3 
//	工具：
//		1、to_string() 
//			经重载，可以将大部分数据类型转化为string类型。
//		2、stoi(str, pos, base) 
//			将str转化为int类型，pos指定字符串中开始位置，base指定进制。
//	错误：
//		1、双重循环
//			从左到右，从上到下遍历，最初想当然循环的顺序反了。
//		2、删除测试
//			及时删除测试内容。
//		3、条件判断 if-else
//			安排的顺序需要合理设计，这次如果和上一个字符的颜色相同就不转义，
//			但是提前判断了是否和终端颜色相同，导致多出很多连续的重置转义。
//			（主要是因为边看边写没有思考清楚）
//	成功：
//		1、伪代码
//			最初的设计非常重要，磨刀不误砍柴工，设计好的话可以减少逻辑错误，
//			把精力放在语法错误上。
//		2、读题
//			最近两次CSP-3都是大阅读理解题，最初的一段会引入一点新知识，
//			这些新知识对理解下面的题目比较重要但是可能含有大量冗余信息。
//			一定要仔细分析题目需求，将逻辑用伪代码梳理清楚才下笔。
//
////////////////////////////////////////////////////////////////////// 
#include<bits/stdc++.h>
using namespace std;

const int MAXM = 1920;
const int MAXN = 1080;
int m, n, p, q;
string pix[MAXN][MAXM];

void calculate_pix(int row, int col, int &r, int &g, int &b) {
	r = 0, g = 0, b = 0;
	for (int i = 0; i < q; i++) {
		for (int j = 0; j < p; j++) {
			r += stoi(pix[q*row + i][p*col + j].substr(0, 2), 0, 16);
			g += stoi(pix[q*row + i][p*col + j].substr(2, 2), 0, 16);
			b += stoi(pix[q*row + i][p*col + j].substr(4, 2), 0, 16);
		}
	}
	int num = p*q;
	r /= num; g /= num; b /= num;
}
 
void get_pix(int row, int col) {
	string s1, s2;
	getline(cin, s1);
	if (s1.size() == 2) {
		for (int i = 0; i < 6; i++) s2 += s1[1];
	} else if (s1.size() == 4) {
		s2 += s1[1]; s2 += s1[1];
		s2 += s1[2]; s2 += s1[2];
		s2 += s1[3]; s2 += s1[3];
	} else {
		s2 = s1.substr(1, 6);
	}
	pix[row][col] = s2;
}

int main() {
	//input
	scanf("%d%d%d%d%*c", &m, &n, &p, &q);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			get_pix(i, j);
		}
	}
	
	//一般在此处有测试内容，最终提交务必删除

	//output
	for (int i = 0; i < n/q; i++) {
		//output line
		int r, g, b;
		int p_r = 0, p_g = 0, p_b = 0;
		for (int j = 0; j < m/p; j++) {
			calculate_pix(i, j, r, g, b);
			string s = "";
			if (r == p_r && g == p_g && b == p_b) {
				;
			} else if (r == 0 && g == 0 && b == 0) {
				s += "\x1b[0m";
			} else {
				s += "\x1b[48;2;";
				s += to_string(r); s += ";";
				s += to_string(g); s += ";";
				s += to_string(b); s += "m";
			}
			s += " ";
			for (int k = 0; k < s.size(); k ++) {
				printf("\\x%02X", s[k]);
			}
			//fresh the var
			p_r = r; p_g = g; p_b = b;
		}
		//reset terminal and \n
		string s = "";
		if (r != 0 || g != 0 || b != 0) {
			p_r = 0; p_g = 0; p_b = 0; //reset to 0
			s += "\x1b[0m";
		}
		s += '\n';
		for (int j = 0; j < s.size(); j++) {
			printf("\\x%02X", s[j]);
		}
	}
	return 0;
}
