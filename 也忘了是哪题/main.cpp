#include<cstdio>
#include<algorithm>
#define MAXN 9999
using namespace std;

bool HashTable[MAXN];	//��һ��Ҫ�á��Ƿ񡱱�ʾ·�� 
int N;
int in[101];

int cmp(int a, int b) {
	return a > b;
}

int main() {
	scanf("%d", &N);
	for(int i = 0; i < N; i++) {
		scanf("%d", in + i);
	}
	for(int i = 0; i < N; i++) {
		int n = in[i];
		while(n != 1) { 
			if(n != in[i]) HashTable[n] = true; //��ʵ�����ü����ķ�ʽ��ʾ·��������Ϊ1�Ŀ϶�����Ҫ���� 
			if(n % 2 == 0) n = n / 2;
			else n = (3 * n + 1) / 2;
		}
	}
	for(int i = 0; i < N; i++) {
		if(HashTable[in[i]]) in[i] = 0;
	}
	sort(in, in + 101, cmp); //����sort֮��������������0 
	for(int i = 0; i < N; i++) {
		if(in[i] == 0) break; 
		if(i != 0) printf(" ");
		printf("%d", in[i]);
	}
	printf("\n");
	return 0;
}
