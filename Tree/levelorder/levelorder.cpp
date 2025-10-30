#include <iostream>
#include <queue>
#include <deque>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    
    explicit TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

void printLevelOrder(TreeNode* root) {
    
    if(root) {
        std::queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            std::cout << current->data << ' ';
            if(current->left) {
                q.push(current->left);
            }
            if(current->right) {
                q.push(current->right);
            }
        }
        std::cout << std::endl;
    }
    
}

int main () {
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    printLevelOrder(root);
    
    return 0;
}