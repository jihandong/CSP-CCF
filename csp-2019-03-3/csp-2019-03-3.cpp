/* 磁盘恢复
 * 要点：
 * （1）输入：使用fgetc来处理长字符串输入比scanf更快；
 * 		注意之前需要使用%*c吸掉换行符；
 * （2）常数级优化：是毫无意义的，不要再上面浪费时间（除了输入输出）；
 * （3）条件判断：程序主体计算部分占据一半分数，条件判断也可以占据一半分数，
 * 		但是条件判断比计算容易地多，一定要注意条件判断的corner case，
 * 		避免愚蠢的失分；
 * （4）格式转化：sscanf可以对变量进行格式转换，非常方便，应该合理利用。
 */
#include<bits/stdc++.h>
using namespace std;

char Array[1010][102500];
char Temp[9]; 
int Req[1010];
int n, s, l, m;

int main() {
	// 1.input
	scanf("%d%d%d", &n, &s, &l);
	for (int i = 0; i < l; i++) {
		int pd;
		scanf("%d%*c",&pd);
		fgets(Array[pd], 102500, stdin);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", Req + i);
	}
	//2.output
	int nblocks = (n - 1) * strlen(Array[0]) / 8;
	int nblocks_layer_belt = s * (n - 1);
	for (int i = 0; i < m; i++) {
		int vb = Req[i];
		// 2.1. check vbphy disk and phy block
		int pd = (vb / s) % n;
		int pb = s * (vb / nblocks_layer_belt) + vb % s;
		// 2.2. check vb and print
		if (vb >= nblocks ||(Array[pd][0] == '\0' && n - 1 > l)) {
			printf("-\n");
		} else if (Array[pd][0] != '\0') { //valid
			for (int k = 0; k < 8; k++)
				putchar(Array[pd][pb * 8 + k]);
			putchar('\n');
		} else { //invalid but recoverable
			int ans = 0, tmp;
			for (int j = 0; j < n && j != pd; j++) {
				for (int k = 0; k < 8; k++)
					Temp[k] = Array[j][pb * 8 + k];
				Temp[8] = '\0';
				sscanf(Temp, "%X", &tmp);
				ans ^= tmp;
			}
			printf("%08X\n", ans);
		}
	}
	return 0;
}
