/*
��������

��Ŀ����

����һ���ַ���������С�ڵ���200��Ȼ���������������
����

���������ж��飬ÿ������һ���ַ�����
���

����ÿ������,��������ú�Ľ����
��������

tianqin

�������

niqnait

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
		for(int i = s.size()-1; i >= 0; i--) {
			printf("%c", s[i]);
		}	printf("\n");
	}
	return 0;
}

