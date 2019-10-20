#include<bits/stdc++.h>
using namespace std;

int main() {
	int a, da, b, db;
	while((scanf("%d%d%d%d", &a, &da, &b, &db)) != EOF) {
		//count
		int cnta = 0, cntb = 0;
		string stra = to_string(a), strb = to_string(b);
		for (int i = 0; i < stra.size(); i++) {
			if(stra[i] - '0' == da) cnta++;
		}
		for (int i = 0; i < strb.size(); i++) {
			if(strb[i] - '0' == db) cntb++;
		}
		//make result
		string pa, pb;
		pa.assign(cnta, da + '0');
		pb.assign(cntb, db + '0');
		int res1 = (cnta == 0)? 0 : stoi(pa);
		int res2 = (cntb == 0)? 0 : stoi(pb);
		printf("%d\n", res1 + res2);
	}
	return 0;
}
