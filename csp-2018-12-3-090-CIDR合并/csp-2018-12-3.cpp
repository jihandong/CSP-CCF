/* CIDR合并：90
 */
#include<bits/stdc++.h>
using namespace std;

const int maxn = 1000000;
struct ip {
	unsigned addr;
	int len;
} ips[maxn];
int rank[maxn];
int next[maxn];
int last[maxn];
int n;

bool cmp(int i, int j) {
	if (ips[i].addr != ips[j].addr)
		return ips[i].addr < ips[j].addr;
	else
		return ips[i].len < ips[j].len;
}

int main() {
	// input
	scanf("%d%*c", &n);
	string s;
	for (int i = 0; i < n; i++) {
		getline(cin, s);
		int pos = 0, next, cut, c = 0;
		s += ".";
		if ((cut = s.find("/", pos)) != string::npos)
			s[cut] = '.';
		else
			cut = 0;
		while ((next = s.find(".", pos)) != string::npos) {
			if (pos - 1 != cut)
				ips[i].addr += (atoi(s.substr(pos, next - pos).c_str()) <<  (24 - 8*c));
			else if (cut != 0)
				ips[i].len = atoi(s.substr(pos, next - pos).c_str());
			else ;
			pos = next + 1;
			c++;
		}
		if (cut == 0)
			ips[i].len = c * 8;
	}

	//initial
	for (int i = 0; i < n; i++) {
		rank[i] = i;
		next[i] = n;
		last[i] = n;
	}
	
	// sort
	sort(rank, rank + n, cmp);

	// first-combine
	for (int a = 0; a < n; a = next[a]) {
		int ra = rank[a];
		unsigned abegin = ips[ra].addr & (~0 << (32 - ips[ra].len));
		unsigned aend = ips[ra].addr | ~(~0 << (32 - ips[ra].len));
		for (int b = a + 1; b < n; b++) {
			int rb = rank[b];
			unsigned bbegin = ips[rb].addr & (~0 << (32 - ips[rb].len));
			unsigned bend = ips[rb].addr | ~(~0 << (32 - ips[rb].len));
			if (abegin <= bbegin && bend <= aend) {
				continue;
			} else {
				next[a] = b;
				last[b] = a;
				break;
			}
		}	
	}

	// second-conbine
	for (int a = 0; a < n; ) {
		int b;
		if ((b = next[a]) == n)
			break;
		int ra = rank[a];
		int alen = ips[ra].len;
		unsigned apre = ips[ra].addr >> (32 - alen);
		unsigned abit = apre & 1;
		apre >>= 1;
		int rb = rank[b];
		int blen = ips[rb].len;
		unsigned bpre = ips[rb].addr >> (32 - blen);
		unsigned bbit = bpre & 1;
		bpre >>= 1;
		if (apre == bpre && alen == blen && abit + bbit == 1) {
			next[a] = next[b];
			if (alen > 0)
				ips[ra].len--;
			if (last[a] < n)
				a = last[a];
		} else
			a = next[a];
	}

	// output
	for (int i = 0; i < n; i = next[i]) {
		int ri = rank[i];
		unsigned iaddr = ips[ri].addr;
		printf("%u.%u.%u.%u/%d\n", (iaddr>>24)&0xFF, (iaddr>>16)&0xFF, (iaddr>>8)&0xFF, iaddr&0xFF, ips[ri].len);
	}
}
