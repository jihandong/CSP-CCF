#include<bits/stdc++.h>
using namespace std;

map<string,vector<int> > mp;

int main() {
	//var
	int N, K;
	while((scanf("%d%d", &N, &K)) == 2) {
		//initial
		mp.clear();
		//input course
		for(int i = 0; i < K; i++) {
			int index, num;
			scanf("%d%d", &index, &num);
			//name list of couse 
			for(int j = 0; j < num; j++) {
				string name; cin >> name;
				if(mp.find(name) == mp.end()) {
					vector<int> v;
					mp[name] = v;
				}
				mp[name].push_back(index);
			}
		}
		//output search
		for(int i = 0; i < N; i++) {
			string name; cin >> name;
			printf("%s %d", name.c_str(), mp[name].size());
			sort(mp[name].begin(), mp[name].end());
			for(int i = 0; i < mp[name].size(); i++) {
				printf(" %d", mp[name][i]);
			}	printf("\n");
		}
	}
	return 0;
}
