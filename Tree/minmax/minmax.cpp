#include <iostream>
#include <queue>
#include <deque>
#include <climits>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    
    explicit TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

int findMin(TreeNode* root) {
    if(!root) {return INT_MAX;}
    return std::min(std::min(root->data, findMin(root->right)), findMin(root->left));
    
}

int findMax(TreeNode* root) {
    if(!root) {return INT_MIN;}
    return std::max(std::max(root->data, findMax(root->right)), findMax(root->left));
    
}

int main () {
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    std::cout << findMin(root) << std::endl;
    std::cout << findMax(root) << std::endl;
    
    return 0;
}