#include<bits/stdc++.h>
using namespace std;

stack<double> oprd;
stack<char> oprt;
map<char,int> p;

void operate() {
	char   op = oprt.top(); oprt.pop();
	double d2 = oprd.top(); oprd.pop();
	double d1 = oprd.top(); oprd.pop();
	switch(op) {
		case '+': oprd.push(d1+d2); break;
		case '-': oprd.push(d1-d2); break;
		case '*': oprd.push(d1*d2); break;
		case '/': oprd.push(d1/d2); break;
	}
}

int main() {
	//var
	p['+'] = 0; p['-'] = 0;
	p['*'] = 1; p['/'] = 1;
	while(true) {
		//input line
		string s;
		getline(cin, s);
		if(s == "0") break; //end case
		stringstream input(s);
		//input word
		string w;
		while(input >> w) {
			char op = w[0];
			if(op == '+' || op == '-' || op == '*' || op == '/') {
				//clear oprt stack
				//清空栈中优先级大于等于新op的操作符 
				while(!oprt.empty() && p[op] <= p[oprt.top()]) {
					operate();
				}
				oprt.push(op);
			} else {
				double num = stoi(w);
				oprd.push(num);
			}
		}
		//clear stack
		while(!oprt.empty()) {
			operate();
		}
		//output
		printf("%.2lf\n", oprd.top());
		oprd.pop();
	}
	return 0;
}
