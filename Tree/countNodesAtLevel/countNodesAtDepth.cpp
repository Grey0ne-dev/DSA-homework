#include <iostream>
#include <queue>
#include <deque>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    
    explicit TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

int countNodesAtDepth(TreeNode* root, int level) {
    if (!root || level < 0) return 0;
    
    std::queue<TreeNode*> q;
    q.push(root);
    int currentLevel = 0;
    
    while (!q.empty()) {
        int levelSize = q.size();
        
        if (currentLevel == level) {
            return levelSize;
        }
        
        for (int i = 0; i < levelSize; i++) {
            TreeNode* current = q.front();
            q.pop();
            
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
        
        currentLevel++;
    }
    
    return 0;
}

int main () {
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    std::cout << countNodesAtDepth(root, 1) << std::endl;
    
    return 0;
}