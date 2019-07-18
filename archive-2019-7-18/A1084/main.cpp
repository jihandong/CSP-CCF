#include<cstdio>
using namespace std;

char in[82];
char out[82];
bool HashTable[128] = {false}; 

int main() {
	scanf("%s%s", in, out);
	char *pout = out;
	for(int i = 0; in[i] != 0; i++) {
		if(in[i] != *pout) {
			if(!HashTable[in[i]]) {
				HashTable[in[i]] = true;
				if(in[i] == '_' || (in[i] <= '9' && in[i] >= '0'))
					printf("%c", in[i]);
				if(in[i] <= 'Z' && in[i] >= 'A') { //居然TM忘了加等于，大艹 
					printf("%c", in[i]);
					HashTable[in[i]+'a'-'A'] = true;
				}
				if(in[i] <= 'z' && in[i] >= 'a') { 
					printf("%c", in[i]+'A'-'a');
					HashTable[in[i]+'A'-'a'] = true;
				}
			}
		}
		else pout++; 
	}
	printf("\n");
	return 0;
}
