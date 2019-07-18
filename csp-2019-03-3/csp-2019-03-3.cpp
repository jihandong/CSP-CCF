#include<cstdio>
#include<string.h>
#define MAX_D_NUM 1010
#define MAX_D_SIZE 100000
#define IS_NUM(c) ((c) >= '0' && (c) <= '9')

char Array[MAX_D_NUM][MAX_D_SIZE];
int Req[MAX_D_NUM];
int n, s, l, m;

char recover_half_byte(int bias) {
	char result = 0;
	for (int i = 0; i < l; i++) {
		char hb = Array[i][bias];
		if(IS_NUM(hb)) 
			result ^= (hb - '0');
		else
			result ^= (hb - 'A' + 10);
	}
	if (result < 10)
		return result + '0';
	else
		return result + 'A' - 10;
}

void access_block(int vb) {
	// 1. check vb
	// (1) forget to divide 8
	// (2) forget to return
	// (3) corner case
	if (vb >= (n - 1) * (strlen(Array[0]) / 8)) {
		printf("-\n");
		return;
	}
	// 2. phy disk and phy block 
	int layer_belt_size = s * (n - 1);
	int layer = vb / layer_belt_size;
	int P = n - 1 - layer % n;
	int bias = vb % layer_belt_size;
	int pd = (P + 1 + bias / s) % n;
	int pb = s * layer + bias % s;
	// 3. print
	if (pd >= l) { //lost
		if (l < n - 1) { // cannot revocer
			printf("-\n");
			return;
		}
		for (int i = 0; i < 8; i++)
			putchar(recover_half_byte(pb * 8 + i));
	} else { //directly read
		for (int i = 0; i < 8; i++)
			putchar(Array[pd][pb * 8 + i]);
	}
	putchar('\n');
}

int main() {
	//input
	// (1) write "%m" stupidly
	scanf("%d%d%d", &n, &s, &l);
	for(int i = 0; i < l; i++) {
		int pd = 0;
		scanf("%d", &pd);
		char *Disk = Array[pd];
		scanf("%s", Disk);
	}
	scanf("%d", &m);
	for(int i = 0; i < m; i++) {
		scanf("%d", Req + i);
	}
	//output 
	for(int i = 0; i < m; i++) {
		//read phy block and print
		access_block(Req[i]);
	}
	return 0;
} 
