/*
���� A: ��һ�� A+B

��Ŀ����

�����������������Ͷ���ķǸ�10��������A��B(<=2^31-1)�����A+B��m (1 < m <10)��������
����

�����ʽ����������������ɲ���������ÿ����������ռһ�У�����m��A��B��ֵ��
��mΪ0ʱ���������
���

�����ʽ��ÿ���������������ռһ�У����A+B��m�������� 

��������

2 4 5
8 123 456
0

�������

1001
1103
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;

int main() {
	//var
	int m;
	LL a, b;
	//loop
	while((scanf("%d%lld%lld", &m, &a, &b)) == 3) {
		LL sum = a + b;
		string s = "";
		//change
		do {
			s += ((sum % m) + '0');
			sum /= m; 
		} while(sum != 0);
		//output
		for(int i = s.size()-1; i >= 0; i--) {
			printf("%c", s[i]);
		}
		printf("\n");
	}
	
	return 0;
} 
