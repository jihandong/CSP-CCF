#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;

int T;

int main() {
	scanf("%d", &T);
	for (int i = 0; i < T ;i++){
		//input
		LL a, b, c;
		scanf("%lld%lld%lld",&a, &b, &c);
		//ouput
		if (a + b > c) {
			printf("Case #%d: true\n", i + 1);
		} else {
			printf("Case #%d: false\n", i + 1);
		}
	}
}
