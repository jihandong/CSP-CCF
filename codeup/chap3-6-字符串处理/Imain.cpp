/*
���ַ��������Ĵ�

��Ŀ����

����һ���ַ����ж��Ƿ��ǻ��Ĵ��������Ĵ�����һ�������ͷ�����һ�����ַ��������硰level�����ߡ�noon���ȵȾ��ǻ��Ĵ���
����

һ���ַ��������Ȳ�����255��
���

����ǻ��Ĵ��������YES�������������NO����
��������

12321

�������

YES

*/
#include<bits/stdc++.h>
using namespace std;

int main() {
	//var
	while(true) {
		if(cin.eof()) break;
		string s;
		getline(cin, s);
		bool flag = true;
		for(int i = 0; i < s.size()/2; i++) {
			if(s[i] != s[s.size()-1-i]) {
				flag = false;
				break;
			}
		}
		//output
		if(flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
