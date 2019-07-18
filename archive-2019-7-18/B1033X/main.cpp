#include<cstdio>
#include<cstring>

bool hashtable[256];
char B[256];
char S[100010]; //10^5��Χ©��һ����ͺ�����������������ܻᵼ�¶δ��� 

int main() {
	memset(hashtable, true, sizeof(hashtable)); //��ʼ�� 
	scanf("%s%s", B, S);
	for(int i = 0; B[i] != 0; i++) {
		hashtable[B[i]] = false;
		if(B[i] == '+') for(int j = 'A'; j <= 'Z'; j++) hashtable[j] = false;
		if('A' <= B[i] && B[i] <= 'Z')	hashtable[B[i]+'a'-'A'] = false;
	}
	for(int i = 0; S[i] != 0; i++) {
		if(hashtable[S[i]]) printf("%c", S[i]);
	}
	printf("\n");
	return 0;
} 
