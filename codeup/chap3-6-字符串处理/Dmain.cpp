/*
��Ŀ����

����һ���ַ������Իس��������ַ�������<=100�������ַ��������ɸ�������ɣ�����֮����һ���ո���������е������ִ�Сд������Ҫ�����е�ĳ�������滻����һ�����ʣ�������滻֮����ַ�����
����
�������ݡ�ÿ�������������3�У�
��1���ǰ���������ʵ��ַ��� s��
��2���Ǵ��滻�ĵ���a��(����<=100)
��3����a�����滻�ĵ���b��(����<=100)
s, a, b ��ǰ�������涼û�пո�
���
ÿ�������������ֻ�� 1 �У�
��s�����е���a�滻��b֮����ַ�����
��������

I love Tian Qin
I
You

�������

You love Tian Qin
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
	//var
	//input
	while(true) {
		if(cin.eof()) break;
		string a, b, s;
		getline(cin, s);
		getline(cin, a);
		getline(cin, b);
		int pos = 0;
		while((pos = s.find(a, pos)) != string::npos) {
			s.replace(pos, a.size(), b);
			pos += b.size();
		}
		//output
		printf("%s\n", s.c_str());
	}
	return 0;
}

