#include<bits/stdc++.h>
using namespace std;

struct node {
	int data;
	node* next;
	node() {}
	node(int d, node* n) {
		this->data = d;
		this->next = n;
	}
};

node* mk_node(int val) {
	node* n = new node;
	n->data = val;
	n->next = NULL;
	return n;
}

void delete_node(node* n) {
	n->data = 0;
	n->next = NULL;
	delete n;
}

node* list_create() {
	node* head = mk_node(0);;
	return head;
}

void list_add(node* list, int val) {
	if(!list)	return;
	node* p2 = list->next;
	node* n = mk_node(val);
	list->next = n;
	n->next = p2; 
}

void list_delete(node* list) {
	if(list) {
		node* pnext = list->next;
		delete list;
		list_delete(pnext);//recurrsive delete
	}
}

void list_insert(node* list, int pos, int val) {
	node* n = mk_node(val);
	//move pointer to location
	node* p1 = list;
	node* p2 = list;
	while(pos-- && p2) {
		p1 = p2;
		p2 = p2->next;
	}
	//±éÀúÍê±Ï 
	if(pos < 0) { //insert node
		p1->next = n;
		n->next = p2;
		printf("insert OK\n");
	} else { //wrong
		printf("insert fail\n");
	}
}

void list_get(node* list, int pos) {
	node* p2 = list;
	while(pos-- && p2) p2 = p2->next;
	if(p2) { //get node
		printf("%d\n", p2->data);
	} else { //fail
		printf("get fail\n");
	}
}

void list_delete(node* list, int pos) {
	//move pointer to location
	node* p1;
	node* p2 = list;
	while(pos-- && p2) {
		p1 = p2;
		p2 = p2->next;
	}
	if(p2) { //delete node
		node* p3 = p2->next;
		delete_node(p2);
		p1->next = p3;
		printf("delete OK\n");
	} else { //wrong
		printf("delete fail\n");
	}
}

void list_show(node* list) {
	node* p2 = list;
	if(!p2 || !p2->next) {
		printf("Link list is empty\n");
	} else {
		while(p2) {
			if(p2 != list && p2 != list->next)
				printf(" ");
			if(p2 != list)
				printf("%d", p2->data); 
			p2 = p2->next;
		}	printf("\n");
	}
}

int main() {
	//var
	int N, M;
	while((scanf("%d", &N)) == 1) {
		//create list
		node* head = list_create();
		for(int i = 0; i < N; i++) {
			int tmp;
			scanf("%d", &tmp);
			list_add(head, tmp);
		}
		//cmd
		scanf("%d", &M);
		string s; 
		for(int i = 0; i < M; i++) {
			cin >> s;
			int pos, val;
			if(s == "get") { 
				scanf("%d", &pos);
				list_get(head, pos);
			} else if(s == "insert") {
				scanf("%d%d", &pos, &val);
				list_insert(head, pos, val);
			} else if(s == "delete") {
				scanf("%d", &pos);
				list_delete(head, pos);
			} else {
				list_show(head);
			}
		}
		//delete list
		list_delete(head);
	}
	return 0;
}
