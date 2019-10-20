#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	while((scanf("%d%d", &n, &m)) > 0) {
		//input
		string stra = to_string(n);
		string strb = to_string(m);
		//output
		int a = 0, b = 0;
		for (int i = 0; i < stra.size(); i++) 
			a += (stra[i] - '0');
		for (int i = 0; i < strb.size(); i++) 
			b += (strb[i] - '0');
		printf("%d\n", a * b);
	}
	return 0;
}
