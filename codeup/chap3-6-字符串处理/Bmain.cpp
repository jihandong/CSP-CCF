/*
����ĸ��д

��Ŀ����

��һ���ַ����е����е��ʣ�������ʵ�����ĸ���Ǵ�д��ĸ����ѵ��ʵ�����ĸ��ɴ�д��ĸ��
���ַ����У�����֮��ͨ���հ׷��ָ����հ׷��������ո�(' ')���Ʊ��('\t')���س���('\r')�����з�('\n')��
����

����һ�У���������ַ���������С��100����
���

�����ж���������ݣ�����ÿ�����ݣ�
���һ�У�ת������ַ�����
��������

if so, you already have a google account. you can sign in on the right.

�������

If So, You Already Have A Google Account. You Can Sign In On The Right.

*/
#include<bits/stdc++.h>
using namespace std;

int main() {
	//var
	string s;
	//input
	while(true) {
		if(cin.eof()) break;
		getline(cin, s);
		//corner case
		if(s[0] >= 'a' && s[0] <= 'z')
			s[0] += ('A' - 'a');
		for(int i = 0; i < s.size(); i++) {
			if(s[i] == ' ' || s[i] == '\t' || s[i] == '\r' || s[i] == '\n') {
				if(i + 1 == s.size()) {
					break;
				} else if(s[i+1] >= 'a' && s[i+1] <= 'z') {
					s[i+1] += ('A' - 'a');
				}
			}
		}
		//output
		printf("%s\n", s.c_str());
	}
	
	return 0;
}
