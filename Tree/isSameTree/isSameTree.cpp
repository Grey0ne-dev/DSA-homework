#include <iostream>
#include <queue>
#include <deque>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    
    explicit TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

bool isSameTree(TreeNode* root1, TreeNode* root2) {
        if(root1 == root2) {
            return true;
        }
        if(!(root1 && root2)) {
        return false;
        }
        if(root1->data != root2->data) {
            return false;
        }
    return true && isSameTree(root1->left, root2 -> left) && isSameTree(root1->right, root2->right);
    }

int main () {
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    root2->left->left = new TreeNode(4);
    
    std::cout << std::boolalpha << isSameTree(root, root2) << std::endl;
    
    return 0;
}