#include<bits/stdc++.h>
using namespace std;

hash_map<string,vector<int> > mp;

int main() {
	//var
	int N, K;
	while((scanf("%d%d", &N, &K)) == 2) {
		//initial
		mp.clear();
		//input course
		for(int i = 0; i < K; i++) {
			int index, num;
			scanf("%d%d%*c", &index, &num);
			string s;
			getline(cin, s);
			//name list of couse 
			for(int j = 0; j < num; j++) {
				string name = s.substr(j*5, 4);
				if(mp.find(name) == mp.end()) {
					vector<int> v;
					mp[name] = v;
				}
				mp[name].push_back(index);
			}
		}
		//output search
		string s;
		getline(cin, s);
		for(int i = 0; i < N; i++) {
			string name = s.substr(i*5, 4);
			printf("%s %d", name.c_str(), mp[name].size());
			sort(mp[name].begin(), mp[name].end());
			for(int i = 0; i < mp[name].size(); i++) {
				printf(" %d", mp[name][i]);
			}	printf("\n");
		}
	}
	return 0;
}
