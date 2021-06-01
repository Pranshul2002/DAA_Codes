#include <iostream>
using namespace std;

typedef struct tree
{
	int data;
	struct tree* left;
	struct tree* right;
} node;

int max  = 0;

int Diameter(node* root){
	if(root == NULL){
		return 0;
	}
	int left = Diameter(root->left);
	int right = Diameter(root->right);
	return left + right + 1;
}

int main(){
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
	cout<<Diameter(root);
}