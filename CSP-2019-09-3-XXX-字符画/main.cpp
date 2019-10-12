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
	
	/*test
	printf("pix:\n");
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%s", pix[i][j].c_str());
		}
		printf("\n");
	}
	*/
	
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
