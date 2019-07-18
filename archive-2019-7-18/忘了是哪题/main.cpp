#include<cstdio>

int HashTable1[128], HashTable2[128];
char sell[1010], need[1010];

int main() {
	scanf("%s%s", sell, need);
	for(int i = 0; sell[i] != 0; i++)	HashTable1[sell[i]]++;
	for(int i = 0; need[i] != 0; i++)	HashTable2[need[i]]++;
	int needmore = 0, toomuch = 0, flag = 1;
	for(int i = 0; i < 128; i++) {
		if(HashTable1[i] > HashTable2[i])
			toomuch += (HashTable1[i] - HashTable2[i]);
		if(HashTable1[i] < HashTable2[i]) {
			flag = 0;
			needmore += (HashTable2[i] - HashTable1[i]);
		}
	}
	if(flag) printf("Yes %d\n", toomuch);
	else printf("No %d\n", needmore);
	return 0;
}
