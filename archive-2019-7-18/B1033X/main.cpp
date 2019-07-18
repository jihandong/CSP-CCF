#include<cstdio>
#include<cstring>

bool hashtable[256];
char B[256];
char S[100010]; //10^5范围漏了一个零就很致命，数组溢出可能会导致段错误 

int main() {
	memset(hashtable, true, sizeof(hashtable)); //初始化 
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
