#include <iostream>
using namespace std;

typedef struct tree
{
	int data;
	struct tree* left;
	struct tree* right;
} node;

void inorder(node* root) {
	if (root == NULL)
		return;
	inorder(root->left);
	cout << root->data << endl;
	inorder(root->right);
}

void preorder(node* root) {
	if (root == NULL)
		return;
	cout << root->data << endl;
	preorder(root->left);
	preorder(root->right);
}

void postorder(node* root) {
	if (root == NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	cout << root->data << endl;
}

int height(node* root) {
	if (root == NULL)
		return 0;
	int a = height(root->left);
	int b = height(root->right);
	if (a > b) {
		return a + 1;
	} else {
		return b + 1;
	}
}

int main() {
	node* root = (node*)malloc(sizeof(node));
	root->data = 4;
	root->left = (node*)malloc(sizeof(node));
	root->left->data = 5;
	root->right = (node*)malloc(sizeof(node));
	root->right->data = 6;
	root->right->left = NULL;
	root->right->right = NULL;
	root->left->left = (node*)malloc(sizeof(node));
	root->left->left->data = 1;
	root->left->right = NULL;
	root->left->left->left = (node*)malloc(sizeof(node));
	root->left->left->left->data = 2;
	root->left->left->left->left = NULL;
	root->left->left->left->right = NULL;
	root->left->left->right = NULL;
	cout<<"Inorder:"<<endl;
	inorder(root);
	cout<<"Preorder:"<<endl;
	preorder(root);
	cout<<"Postorder:"<<endl;
	postorder(root);
	cout<<"Height: "<<height(root)<<endl;
	return 0;
}

