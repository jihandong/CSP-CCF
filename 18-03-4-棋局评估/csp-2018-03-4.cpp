#include<bits/stdc++.h>
using namespace std;

int n;
int chess[5][3][3];

void input() {
	scanf("%d", n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				scanf("%d", &chess[i][j][k]);
			}
		}
	}
}

void output() {
	for (int i = 0; i < n; i++) {
		printf("%d\n", count(i));
	}
}

int main() {
	input();
	output();
	return 0;
} 
