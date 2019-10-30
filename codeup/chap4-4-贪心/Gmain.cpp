#include<bits/stdc++.h>
using namespace std;

int main() {
	//var
	int M;
	//input
	while((scanf("%d", &M)) > 0) {
		string s = "";
		if(M/50 > 0) s += ("50*" + to_string(M/50) + "+");	M %= 50;
		if(M/20 > 0) s += ("20*" + to_string(M/20) + "+");	M %= 20;
		if(M/10 > 0) s += ("10*" + to_string(M/10) + "+");	M %= 10;
		if(M/5  > 0) s += ("5*"  + to_string(M/5 ) + "+");	M %= 5 ;
		if(M    > 0) s += ("1*"  + to_string(M   ) + "+");
		s.erase(s.end() - 1);
		printf("%s\n", s.c_str());
	}
	return 0;
}
