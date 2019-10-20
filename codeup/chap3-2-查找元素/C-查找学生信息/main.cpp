#include<bits/stdc++.h>
using namespace std;

int N, M;
string Stu[1001];
string ID[1001]; 

int main() {
	while((scanf("%d%*c", &N)) != EOF) {
		//input message
		for(int i = 0; i < N; i++) {
			getline(cin, Stu[i]);
			int pos = Stu[i].find(" ", 0);
			ID[i] = Stu[i].substr(0, pos);
		} 
		//output find
		scanf("%d%*c", &M);
		for(int i = 0; i < M; i++) {
			string str;
			getline(cin, str);
			bool flag = true;
			for(int j = 0; j < N; j++) {
				if(ID[j] == str) {
					printf("%s\n", Stu[j].c_str());
					flag = false;
					break;
				}
			}
			if(flag) printf("No Answer!\n");
		}
	}
	return 0;
}
