#include<cstdio>
#include<vector>
#include<algorithm>
#define MAXN 500000
using namespace std;

vector<int> HashTable[MAXN];
char Q[40010][5];
int N, K;

int myhash(char* str) {
	int result = 0;
	for(int i = 0; i < 4; i++) {
		if(i != 3) result = result * 26 + str[i] - 'A';
		else result = result * 26 + str[i] - '0';
	}
	return result;
}

int main() {
	scanf("%d%d", &N, &K);
	int id, num;
	char name[5];
	for(int i = 0; i < K; i++) {
		scanf("%d%d", &id, &num);
		for(int j = 0; j < num; j++) {
			scanf("%s", name);
			HashTable[myhash(name)].push_back(id);
		}
	}
	for(int i = 0; i < N; i++) scanf("%s", Q[i]);
	for(int i = 0; i < N; i++) {
		int label = myhash(Q[i]);
		int len = HashTable[label].size();
		printf("%s %d", Q[i], len);
		sort(HashTable[label].begin(), HashTable[label].end()); //ÈÝÒ×¸ã´íÓ³Éä¹ØÏµ 
		for(int j = 0; j < len; j++) {
			printf(" %d", HashTable[label][j]);
		}
		printf("\n");
	}
	return 0;
}
