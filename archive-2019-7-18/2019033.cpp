#include<cstdio>
#include<string.h> 
#define MAXM 1001
#define MAXN 100001

int n, s, L, m; 
char disk[MAXM][MAXN];
int b[MAXM];
int circle, size;

char xorL(int bias) {
	char result = 0;
	for(int i = 0; i < L; i++) {
		char bit4 = disk[i][bias];
		if(bit4 >= '0' && bit4 <= '9')
			bit4 -= '0';
		else
			bit4 -= ('A' - 10);
		result ^= bit4;
	}
	if(result >= 0 && result <= 9)
		result += '0';
	else
		result += ('A' - 10);
	return result;
}

int check(int bi) {
	if(L + 1 < n || bi >= size) return -1;
	else return 0;
}

int main() {
	//输入 
	scanf("%d %d %d", &n, &s, &L);
	for(int i = 0; i < L; i++) {
		int j;
		scanf("%d", &j);
		scanf("%s", disk[i]);
	}
	scanf("%d", &m);
	for(int i = 0; i < m; i++) {
		scanf("%d", b + i);
	}
	//输出
	circle = s * (n - 1);
	size = (n - 1) * strlen(disk[0]) / 8;
	for(int i = 0; i < m; i++) {
		if(check(b[i]) < 0) {
			putchar('-');
		} else {
			int k = b[i] / circle;
			int num = ((n - k % n) + (b[i] % circle) / (n - 1)) % n;
			int bias = 8 * (k * s + b[i] % s);
			for(int j = 0; j < 8; j++) {
				if(num < L) //在已有的盘子上 
					putchar(disk[num][bias+j]);
				else //在失去的盘子上 
					putchar(xorL(bias+j));
			}
		}
		putchar('\n');
	}
	return 0;
}
