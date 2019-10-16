////////////////////////////////////////////////////////////////// 
//	csp-19-03-3��24�� 
//  ������
//		1.�沨�����ʽ��
//			֮ǰѧ���������ճ����㷨�ʼǡ���������Ŀ����Ƚϼ򵥣�
//			���Զ�����ɡ�
//		2.map��ʹ�÷ǳ���
//	��ѵ��
//		������Ҫ�ѡ��㷨�ʼǡ���һ�飬����ǧ���򻯣�ģ�������޶���
//		�б�Ҫ����ʱ���һ����ܵõ�300�֣�ʹ�����ȶ����� 
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
