#include <iostream>


struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    
    explicit TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

int countHeight(TreeNode * root) {

	if(!root) {return 0;}
	int l = countHeight(root->left);
	int r = countHeight(root->right);
	return std::max(l,r) + 1;
}


int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    std::cout << countHeight(root) << std::endl;
}
