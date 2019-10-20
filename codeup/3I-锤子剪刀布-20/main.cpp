#include<bits/stdc++.h>
using namespace std;

int N, Awin, Bwin;
int Aout[3], Bout[3];

int main() {
	scanf("%d%*c", &N);
	for(int i = 0; i < N; i++) {
		string str;
		getline(cin, str);
		//A win
		if( (str[0] == 'C' && str[2] == 'J') ||
			(str[0] == 'J' && str[2] == 'B') ||
			(str[0] == 'B' && str[2] == 'C')) {
			Awin++;
			if(str[0] == 'C') Aout[0]++;
			else if(str[0] == 'J') Aout[1]++;
			else Aout[2]++;
		}
		//B win
		if( (str[2] == 'C' && str[0] == 'J') ||
			(str[2] == 'J' && str[0] == 'B') ||
			(str[2] == 'B' && str[0] == 'C')) {
			Bwin++;
			if(str[2] == 'C') Bout[0]++;
			else if(str[2] == 'J') Bout[1]++;
			else Bout[2]++;
		}
	}
	//output B-C-J
	int amax = -1;
	char atype; 
	if(amax < Aout[2]) {
		amax = Aout[2]; 
		atype = 'B';
	}
	if(amax < Aout[0]) {
		amax = Aout[0]; 
		atype = 'C';
	}
	if(amax < Aout[1]) {
		amax = Aout[1]; 
		atype = 'J';
	}
	int bmax = -1;
	char btype;
	if(bmax < Bout[2]) {
		bmax = Bout[2]; 
		btype = 'B';
	}
	if(bmax < Bout[0]) {
		bmax = Bout[0]; 
		btype = 'C';
	}
	if(bmax < Bout[1]) {
		bmax = Bout[1]; 
		btype = 'J';
	}
	printf("%d %d %d\n%d %d %d\n", Awin, N-Awin-Bwin, Bwin, Bwin, N-Awin-Bwin, Awin);
	printf("%c %c\n", atype, btype);
	return 0;
}
