#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10002;

int m[MAXN][MAXN],s[MAXN][MAXN];
void matrix_chain(int a[], int n)
{
	int l, i, j, k, tmp;
	for(l=2; l<=n; l++)
	{
		for(i=1; i<=n-l+1; i++)		//长度为l的区间，其最小下标为1～n-l+1
		{
			j=i+l-1;
			m[i][j] = 0x7fffffff;
			for(k=i; k<j; k++)		//i~k, k+1~j, 所以k<j
			{
				tmp = m[i][k]+m[k+1][j]+a[i-1]*a[k]*a[j];
				if(tmp < m[i][j])
				{
					m[i][j] = tmp;
					s[i][j] = k;
				}
			}
		}
	}

}
void print(int i, int j)
{
	if(i == j)
		printf("A%d",i);
	else{
		printf("(");
		print(i, s[i][j]);
		print(s[i][j]+1, j);
		printf(")");
	}
}
int main()
{
	int n, a[MAXN];
	int i,j,l;
	clock_t start, end;
	srand((int)time(0)); 	//随机数种子  
	for(n = 100; n <= 4000; n += 100)	//输入有n个矩阵
	{
		double cnt = 0;
		for(int c = 0; c < 3; c++) {
			for(i=0; i<n+1; i++) {
					a[i] = ((unsigned) rand()) % 100 + 1;
			}
			//memset(m, 0x7fffffff,sizeof(m));
			for(i=0; i<n+1; i++)
				m[i][i] = 0;
			start = clock();	//程序开始计时
			matrix_chain(a, n);
			end = clock();		//程序结束计时
			cnt += (double)(end-start)/CLOCKS_PER_SEC;
			//printf("%d ",m[1][n]);
			//print(1, n);
		}	cnt /= 3;
		printf("%d\t%lf\n", n, cnt);
	}

	return 0;
}
