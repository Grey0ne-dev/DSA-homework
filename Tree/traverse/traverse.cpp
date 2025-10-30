#include <iostream>


struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    
    explicit TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};


void preorder(TreeNode * root) {
	if(!root) return;
	std::cout << root->data << std::endl;
	preorder(root -> left);
	preorder(root -> right);
}

void inorder(TreeNode * root) {
	if(!root) return;
	inorder(root->left);
	std::cout << root->data << std::endl;
	inorder(root->right);
}

void postorder(TreeNode * root) {
	if(!root) return;
	postorder(root->left);
	postorder(root->right);
	std::cout << root->data << std::endl;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);


    preorder(root);
    inorder(root);
    postorder(root);
}
