#include<bits/stdc++.h>
using namespace std;
 
const int MAXN = 26*26*26*10+1;
vector<int> Stu[MAXN];

int hashf(string s) {
	int sum = 0;
	for(int i = 0; i < 3; i++) {
		sum = sum*26 + s[i] - 'A';
	}	sum = sum*10 + s[3] - '0';
	return sum;
}

void clear_vector(vector<int> &v) {
	vector<int> tmp;
	swap(tmp, v);
}

int main() {
	//var
	int N, K;
	while((scanf("%d%d", &N, &K)) == 2) {
		//initial
		for(int i = 0; i < N; i++) {
			clear_vector(Stu[i]);
		}
		//input course
		for(int i = 0; i < K; i++) {
			int index, num;
			scanf("%d%d%*c", &index, &num);
			string s;
			getline(cin, s);
			//name list of couse 
			for(int j = 0; j < num; j++) {
				string name = s.substr(j*5, 4);
				Stu[hashf(name)].push_back(index);
			}
		}
		//output search
		string s;
		getline(cin, s);
		for(int i = 0; i < N; i++) {
			string name = s.substr(i*5, 4);
			printf("%s %d", name.c_str(), Stu[hashf(name)].size());
			sort(Stu[hashf(name)].begin(), Stu[hashf(name)].end());
			for(int i = 0; i < Stu[hashf(name)].size(); i++) {
				printf(" %d", Stu[hashf(name)][i]);
			}	printf("\n");
		}
	}
	return 0;
}
