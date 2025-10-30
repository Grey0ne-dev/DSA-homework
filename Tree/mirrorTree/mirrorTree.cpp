#include <iostream>
#include <queue>
#include <deque>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    
    explicit TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};



void swapChilds(TreeNode*& root) {
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
}

void mirrorTree(TreeNode*& root) {
    if (!root) return;
    
    std::queue<TreeNode*> q;
    q.push(root);
    
    while(!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        
        swapChilds(current);
        
        if(current->left) { q.push(current->left); }
        if(current->right) { q.push(current->right); }
    }
}

void print(TreeNode* root) {
    if (!root) return;
    
    std::queue<TreeNode*> q;
    q.push(root);
    
    while(!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        
        std::cout << current->data << ' ';
        
        if(current->left) { q.push(current->left); }
        if(current->right) { q.push(current->right); }
    }
    std::cout << std::endl;
}

int main () {
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    
    print(root);
    std::cout << std::endl;
    mirrorTree(root);
    print(root);
    std::cout << std::endl;
    return 0;
}