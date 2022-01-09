#include <stdio.h>
#include <stdlib.h>
#define LEFT 0

typedef struct node {
	int data;
	struct node* left, * right;
}Node;

void dfs_swap(Node* root) {
	Node* tmp = root->left;
	root->left = root->right;
	root->right = tmp;
	if (root->left) dfs_swap(root->left);
	if (root->right) dfs_swap(root->right);
}

void bfs_print(Node* root) {
	int front = 0, size = 1;
	Node* NodeQueue[1024] = { 0 };	//simplified queue
	NodeQueue[front] = root;
	while (size) {
		Node* now = NodeQueue[front];
		if (now != NULL) {
			if (front) putchar(' ');
			printf("%d", now->data);
			NodeQueue[front + size] = now->left;	//push Lchild
			NodeQueue[front + size + 1] = now->right;	//push Rchild
			++front;	//pop
			++size;		//push 2, pop 1, size should inc 1
		}
		else {
			printf(" 0");
			++front;
			--size;
		}
	}
	putchar('\n');
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		int front = 0, size = 1, child = LEFT, tmp;
		Node* NodeQueue[1024] = { 0 };	//simplified queue
		scanf("%d", &tmp);
		Node* root = (Node*)malloc(sizeof(Node));
		root->data = tmp;
		root->left = root->right = NULL;
		NodeQueue[front] = root;

		while (scanf("%d", &tmp) && tmp != -1) {	//not -1, update one single child each time
			if (tmp) {	//not 0
				Node* newNode = (Node*)malloc(sizeof(Node));
				newNode->data = tmp;
				newNode->left = newNode->right = NULL;
				if (child == LEFT) NodeQueue[front]->left = newNode;	//update Lchild
				else {													//update Rchild
					NodeQueue[front++]->right = newNode;	//Rchild is set, pop father
					--size;
				}
				NodeQueue[front + size] = newNode;	//push child
				++size;
			}
			else if (child) { ++front; --size; }	//Rchild is set(NULL though), pop father
			child = !child;		//switch between left node and right node
		}
		dfs_swap(root);
		bfs_print(root);
	}
	return 0;

 } 
