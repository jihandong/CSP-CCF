////////////////////////////////////////////////////////////////// 
//	csp-19-03-3：24点 
//  方法：
//		1.逆波兰表达式：
//			之前学过，本想照抄《算法笔记》，但是题目情况比较简单，
//			可以独立完成。
//		2.map的使用非常灵活：
//	教训：
//		还是需要把《算法笔记》过一遍，题型千变万化，模拟题无限恶心
//		有必要挤出时间过一遍才能得到300分，使保研稳定下来 
//
///////////////////////////////////////////////////////////////// 
#include<bits/stdc++.h>
using namespace std;

int N;
stack<int> num;
stack<char> op;
map<char,int> pr;

void calone() {
	int n2 = num.top(); num.pop();
	int n1 = num.top(); num.pop();
	char o = op.top(); op.pop();
	switch(o) {
		case '+': num.push(n1 + n2); break;
		case '-': num.push(n1 - n2); break;
		case 'x': num.push(n1 * n2); break;
		case '/': num.push(n1 / n2); break;
	}
}

bool cal(string s) {
	int result;
	for (int i = 0; i < s.size(); i++) {
		if (i % 2 == 0) { //num
			num.push(s[i] - '0');
		} else { //op 
			while(!op.empty() && pr[s[i]] <= pr[op.top()]) {
				calone();				
			}
			op.push(s[i]);
		}
	}
	while(!op.empty()) {
		calone();
	}
	return (num.top() == 24);
}

int main() {
	pr['+'] = 0; pr['-'] = 0; pr['x'] = 1; pr['/'] = 1;
	scanf("%d%*c", &N);
	for (int i = 0; i < N; i++) {
		string s;
		getline(cin, s);
		if (cal(s)) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
	return 0;
} 
