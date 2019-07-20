#include<cstdio>
#include<string.h>
#define MAX_D_NUM 1010
#define MAX_D_SIZE 102500
#define IS_NUM(c) ((c) >= '0' && (c) <= '9')

char Array[MAX_D_NUM][MAX_D_SIZE];
bool Valid[MAX_D_NUM]; 
int Req[MAX_D_NUM];
int n, s, l, m;

char recover_half_byte(int bias) {
	char result = 0;
	for (int i = 0; i < n && Valid[i]; i++) {
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
	if (vb >= (n - 1) * (strlen(Array[0]) / 8)) {
		printf("-\n");
		return;
	}
	// 2. phy disk and phy block 
	int pd = (vb / s) % n;
	int pb = s * (vb / (s * (n - 1))) + vb % s;
	// 3. print
	if (Valid[pd]) { //valid or recovered
		for (int i = 0; i < 8; i++)
			putchar(Array[pd][pb * 8 + i]);
	} else { //invalid
		putchar('-');
	}
	putchar('\n');
}

int main() {
	// 1.input
	scanf("%d%d%d", &n, &s, &l);
	for (int i = 0; i < l; i++) {
		int pd;
		scanf("%d", &pd);
		scanf("%s", Array[pd]);
		Valid[pd] = true;
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", Req + i);
	}
	//2.recover
	if (n - 1 == l) {
		int rcv = 0;
		for (; Valid[rcv] && rcv < n; rcv++) ;
		for (int i = 0; i < strlen(Array[0]); i++) {
			 Array[rcv][i] = recover_half_byte(i);
		}
		Valid[rcv] = true;
	}
	//3.output 
	for (int i = 0; i < m; i++) {
		access_block(Req[i]);
	}
	return 0;
} 
