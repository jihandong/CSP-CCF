 /* 并行死锁检查：100
 * 要点
 * （1）上限检查：m、s、n等全局变量一定要明确上限，检查成本低，错误成本高；
 * 		本题将n的上限设置为1010而非10010而失去了20分；
 * （2）输入字符串处理：使用string类型及其方法非常方便；
 * （3）去除debug-printf：最后提交一定要记得删除用于debug的printf，否则0分；
 * （4）清空：这里使用了swap换成一个新queue的方式清空queue，在以后编写程序时，
 * 		也要记得在循环结束后清空“容器”
 * （5）bits/stdc++.h：似乎是个包含了所有c++文件的头文件，似乎可以无脑解决所有依赖？
 */
#include<bits/stdc++.h>
using namespace std;

typedef pair<char, int> command;
int T, n;
queue<command> C[10010]; //great idea! implement tomorrow 

void clear(queue<command>& q) {
	queue<command> empty;
	swap(q, empty);
}

int main() {
	scanf("%d%d%*c", &T, &n);
	while (T--) {
		// 1. input
		string s;
		for (int i = 0; i < n; i++) {
			getline(cin, s);
			s += " "; //保证匹配到最后一条指令
			int pos = 0, next;
			while ((next = s.find(" ", pos)) != string::npos) { //一直找到最后一个
				command cmd;
				cmd.first = *(s.begin() + pos);
				cmd.second = atoi(s.substr(pos + 1, next).c_str());
				C[i].push(cmd);
				pos = next + 1;
			}
		}
		// 2. analysis output
		bool dead_lock = false;
		int empty_queues = 0;
		while (!dead_lock) {
			dead_lock = true; // reset dead_lock check
			empty_queues = 0; // rest empty_queues count
			for (int i = 0; i < n; i++) {
				if (C[i].empty()) {
					empty_queues++;
					continue;
				}
				command cmd1 = C[i].front();
				command cmd2 = C[cmd1.second].front();
				if (cmd2.second == i && (cmd1.first + cmd2.first == 'S' + 'R')) { //简单的检查匹配的方法
					C[i].pop();
					C[cmd1.second].pop();
					dead_lock = false; //只要有指令能够匹配就不会死锁
				} 
			}
		}
		if (empty_queues == n) //如果n个queue均为空，说明指令都顺利执行了
			printf("0\n"); // no dead lock
		else 
			printf("1\n"); // is a dead lock
		// 3. reset queues
		for (int i = 0; i < n; i++) //一定记得清空队列应对下一次输入
			clear(C[i]);
	} 
	return 0;
}
