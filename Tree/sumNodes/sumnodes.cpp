#include <iostream>
#include <queue>
#include <deque>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    
    explicit TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

int sum(TreeNode* root) {
    if(!root) {
        return 0;
    }
    
    return root->data + sum(root->left) + sum(root->right);
}

int main () {
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    std::cout << sum(root);
    
    return 0;
}