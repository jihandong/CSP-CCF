/*
�ַ���ȥ�ض��ַ�

��Ŀ����

�����ַ���s���ַ�c��Ҫ��ȥ��s�����е�c�ַ�������������
����

���������ж��飬ÿ�������ַ���s���ַ�c��
���

����ÿ������,���ȥ��c�ַ���Ľ����
��������

goaod
a

�������

good
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
	//var
	string s1, s2;
	//input
	while(true) {
		if(cin.eof()) break;
		getline(cin, s1);
		getline(cin, s2);
		for(int i = 0; i < s1.size();) {
			if(s1[i] == s2[0]) {
				s1.erase(s1.begin() + i);
			} else {
				i++;
			}
		}
		//output
		printf("%s\n", s1.c_str());
	}
	return 0;
}

