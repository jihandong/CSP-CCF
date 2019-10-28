#include<bits/stdc++.h>
using namespace std;

vector<int> Modd;
vector<int> Meve;
int Buf[10];

bool cmp1(int i, int j) { 
	return i < j;
}

bool cmp2(int i, int j) {
	return i > j;
}

void clear_vector(vector<int> &v) {
	vector<int> tmp;
	swap(tmp, v);
}

int main() {
	//var
	while((scanf("%d%d%d%d%d%d%d%d%d%d", Buf,Buf+1,Buf+2,Buf+3,Buf+4,Buf+5,Buf+6,Buf+7,Buf+8,Buf+9)) == 10) {
		if(cin.eof()) break;
		//initial
		clear_vector(Modd);
		clear_vector(Meve);
		//input
		for(int i = 0; i < 10; i++) {
			if(Buf[i] % 2 == 0) {
				Meve.push_back(Buf[i]);
			} else {
				Modd.push_back(Buf[i]);
			}
		}
		//sort
		sort(Modd.begin(), Modd.end(), cmp2);
		sort(Meve.begin(), Meve.end(), cmp1);
		//output
		for(int i = 0; i < Modd.size(); i++) {
			if(i != 0) printf(" ");
			printf("%d", Modd[i]);
		}
		for(int i = 0; i < Meve.size(); i++) {
			if(i == 0 && Modd.empty())
				;
			else
				printf(" ");
			printf("%d", Meve[i]);
		}	printf("\n");
	}
	return 0;
}
