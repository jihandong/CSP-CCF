#include<bits/stdc++.h>
using namespace std; 

set<string> vis;
string es;

pair<string,string> Aop(pair<string,string> p) {
	swap(p.first[1], p.first[8]);
	swap(p.first[2], p.first[7]);
	swap(p.first[3], p.first[6]);
	swap(p.first[4], p.first[5]);
	p.second += 'A';
	return p;
}

pair<string,string> Bop(pair<string,string> p) {
	pair<string,string> tmp;
	tmp.first = "0";
	tmp.first += p.first[4];
	tmp.first += p.first[1];
	tmp.first += p.first[2];
	tmp.first += p.first[3];
	tmp.first += p.first[6];
	tmp.first += p.first[7];
	tmp.first += p.first[8];
	tmp.first += p.first[5];
	tmp.second = p.second + 'B';
	return tmp;
}

pair<string,string> Cop(pair<string,string> p) {
	pair<string,string> tmp;
	tmp.first = p.first;
	tmp.first[2] = p.first[7];
	tmp.first[3] = p.first[2];
	tmp.first[6] = p.first[3];
	tmp.first[7] = p.first[6];
	tmp.second = p.second + 'C';
	return tmp;
}

void bfs() {
    queue<pair<string, string> > q;
    q.push(pair<string, string>("012345678", ""));
    while(!q.empty()) {
    	pair<string, string> p = q.front();
    	//printf("%s %s\n", p.first.c_str(), p.second.c_str());
    	//leave;
    	if(p.first == es) {
    		printf("%d\n%s\n", p.second.size(), p.second.c_str());
			return;
		}
		q.pop();
        //branch
        pair<string, string> Ap = Aop(p);
        pair<string, string> Bp = Bop(p);
        pair<string, string> Cp = Cop(p);
        if(vis.find(Ap.first) == vis.end()) {
        	vis.insert(Ap.first);
			q.push(Ap);
		}
		if(vis.find(Bp.first) == vis.end()) {
			vis.insert(Bp.first);
			q.push(Bp);
		}
		if(vis.find(Cp.first) == vis.end()) {
			vis.insert(Cp.first);
			q.push(Cp);
		}
    }
}

int main() {
	int tmp[8];
	while((scanf("%d%d%d%d%d%d%d%d", &tmp[0], &tmp[1], &tmp[2], &tmp[3], &tmp[4], &tmp[5], &tmp[6], &tmp[7])) == 8) {
		//initial
		vis.clear();
		es = "0";
		es += (tmp[0] + '0');
		es += (tmp[1] + '0');
		es += (tmp[2] + '0');
		es += (tmp[3] + '0');
		es += (tmp[4] + '0');
		es += (tmp[5] + '0');
		es += (tmp[6] + '0');
		es += (tmp[7] + '0');
		bfs();
	}
	return 0;
} 
