/*

��Ŀ����


NֻС����(1 <= N <= 100)��ÿֻ��ͷ�ϴ���һ������ɫ��ñ�ӡ����ڳƳ�ÿֻ�����������Ҫ���հ��������Ӵ�С��˳���������ͷ��ñ�ӵ���ɫ��ñ�ӵ���ɫ�á�red������blue�����ַ�������ʾ����ͬ��С������Դ���ͬ��ɫ��ñ�ӡ������������������ʾ��


����


�స�����룬ÿ�������������һ��Ϊһ������N����ʾС�������Ŀ��
������N�У�ÿ����һֻ�������Ϣ����һ��Ϊ������100������������ʾ��������������ڶ���Ϊ�ַ�������ʾ�����ñ����ɫ���ַ������Ȳ�����10���ַ���
ע�⣺���������������ͬ��


���


ÿ���������հ���������Ӵ�С��˳����������ñ����ɫ��


��������

1
79 omi
9
46 lcg
92 cru
37 ceq
54 vhr
17 wus
27 tnv
13 kyr
95 wld
34 qox

�������

omi
wld
cru
vhr
lcg
ceq
qox
tnv
wus
kyr

*/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 101;
struct Mouse {
	int weight;
	string color;
	Mouse() {}
	Mouse(int _weight, string _color) {
		this->weight = _weight;
		this->color = _color;
	}
} Mou[MAXN];

bool cmp(Mouse m1, Mouse m2) {
	return m1.weight > m2.weight;
}

int main() {
	//var
	int N;
	while((scanf("%d%*c", &N)) > 0) {
		string s;
		//input
		for(int i = 0; i < N; i++) {
			getline(cin, s);
			int pos = s.find(" ", 0);
			Mou[i] = Mouse(
				stoi(s.substr(0, pos)),
				s.substr(pos+1, s.size()-1-pos)	
			);
		}
		//sort
		sort(Mou, Mou+N, cmp);
		//output
		for(int i = 0; i < N; i++) {
			printf("%s\n", Mou[i].color.c_str());
		}
	}
	return 0;
} 
 
