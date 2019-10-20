#include<bits/stdc++.h>

int n;
int num[100001];

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", num + i);
	int b = num[0]>num[n-1] ? num[0] : num[n-1];
	int s = num[n-1]>num[0] ? num[0] : num[n-1];
	int m1, m2;
	if (n % 2 == 1) {
		m1 = num[(n-1)/2];
		m2 = 0;
	} else {
		m1 = (num[n/2] + num[n/2-1]) / 2;
		if (m1 * 2 != num[n/2] + num[n/2-1])
			m2 = 5;
		else
			m2 = 0;
	}
	if (m2 == 0)
		printf("%d %d %d\n", b, m1, s);
	else
		printf("%d %d.5 %d\n", b, m1, s);
} 
