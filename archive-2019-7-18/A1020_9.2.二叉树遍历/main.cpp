#include<cstdio>
#include<queue>
using namespace std;

int N;
int postorder[30];
int inorder[30];
typedef struct treenode {
	int data;
	struct treenode* left;
	struct treenode* right;
} node;

node* create(int postL, int postR, int inL, int inR) {
	if(postL == postR) return NULL;
	int k;
	for(k = 0; k <= inR; k++) {
		if(inorder[k] == postorder[postR]) break;
	}
	node* root = new node;
	root->data = postorder[postR];
	root->left  = create(postL, postL+k-inL-1, inL, k-1);
	root->right = create(postL+k-inL, postR-1, k+1, inR);
	return root;
} 

void bfs(node* root) {
	queue<node*> Q;
	Q.push(root);
	int count = 0;
	node* tmp;
	while(!Q.empty()) {
		tmp = Q.front();
		printf("%d", tmp->data);
		count++;
		if(count != N) printf(" ");
		else printf("\n");
		Q.pop();
		if(tmp->left) Q.push(tmp->left);
		if(tmp->right) Q.push(tmp->right); 
	}
	return;
}

int main() {
	scanf("%d", &N);
	for(int i = 0; i < N; i++) scanf("%d", postorder + i);
	for(int i = 0; i < N; i++) scanf("%d", inorder + i);
	printf("OK1\n"); //need
	node* root = create(0, N - 1, 0, N - 1);
	printf("OK2\n"); //need
	bfs(root);
	printf("OK3\n"); //need
	return 0;
} 
