#include <iostream>
#include <vector>
#include <limits>
#include <exception>

template <typename T>
class BinarySearchTree {
    struct TreeNode {
        T data;
        TreeNode* left = nullptr;
        TreeNode* right = nullptr;

        explicit TreeNode(T val) : data(val) {}

        ~TreeNode() {
            delete left;
            delete right;
        }

        void print() {
            if (left) left->print();
            std::cout << data << ' ';
            if (right) right->print();
        }

        void insert(const T& val) {
            if (val < data) {
                if (!left)
                    left = new TreeNode(val);
                else
                    left->insert(val);
            } else if (val > data) {
                if (!right)
                    right = new TreeNode(val);
                else
                    right->insert(val);
            }
        }

        bool search(const T& val) {
            if (val < data)
                return left ? left->search(val) : false;
            else if (val > data)
                return right ? right->search(val) : false;
            else
                return true;
        }

        bool isValidBST(T min, T max) {
            if (data <= min || data >= max) return false;
            bool leftOk = left ? left->isValidBST(min, data) : true;
            bool rightOk = right ? right->isValidBST(data, max) : true;
            return leftOk && rightOk;
        }

        size_t size() {
            size_t sum = 1;
            if(left) sum += left->size();
            if(right) sum += right->size();
            return sum;
        }

        T k_smallest_helper(size_t &k) {
            if (left) {
                T v = left->k_smallest_helper(k);
                if (k == 0) return v;
            }
            if (--k == 0) return data;
            if (right) {
                T v = right->k_smallest_helper(k);
                if (k == 0) return v;
            }
            return data;
        }

        static TreeNode* sortedArrayToBST(const std::vector<T>& vec, int start, int end) {
            if (start > end) return nullptr;
            
            int mid = start + (end - start) / 2;
            TreeNode* node = new TreeNode(vec[mid]);
            
            node->left = sortedArrayToBST(vec, start, mid - 1);
            node->right = sortedArrayToBST(vec, mid + 1, end);
            
            return node;
        }

        static TreeNode* findMinNode(TreeNode* node) {
            while (node && node->left) node = node->left;
            return node;
        }

        static TreeNode* deleteNode(TreeNode* root, const T& val) {
            if (!root) return nullptr;

            if (val < root->data) {
                root->left = deleteNode(root->left, val);
            } else if (val > root->data) {
                root->right = deleteNode(root->right, val);
            } else {
                if (!root->left && !root->right) {
                    delete root;
                    return nullptr;
                } else if (!root->left) {
                    TreeNode* tmp = root->right;
                    root->right = nullptr;
                    delete root;
                    return tmp;
                } else if (!root->right) {
                    TreeNode* tmp = root->left;
                    root->left = nullptr;
                    delete root;
                    return tmp;
                } else {
                    TreeNode* minRight = findMinNode(root->right);
                    root->data = minRight->data;
                    root->right = deleteNode(root->right, minRight->data);
                }
            }
            return root;
        }

        static int countInRange(TreeNode* node, const T& low, const T& high) {
            if (!node) return 0;

            if (node->data < low)
                return countInRange(node->right, low, high);
            if (node->data > high)
                return countInRange(node->left, low, high);

            return 1 + countInRange(node->left, low, high) + countInRange(node->right, low, high);
        }

        static bool hasPathSum(TreeNode* node, T sum) {
            if (!node) return false;
            if (!node->left && !node->right) return node->data == sum;

            T remaining = sum - node->data;
            return hasPathSum(node->left, remaining) || hasPathSum(node->right, remaining);
        }
    };

    TreeNode* root = nullptr;

public:
    ~BinarySearchTree() {
        delete root;
    }

    BinarySearchTree(const std::vector<T>& vec) {
        if (!vec.empty()) {
            root = TreeNode::sortedArrayToBST(vec, 0, vec.size() - 1);
        }
    }

    BinarySearchTree() = default;

    void printInorder() {
        if (!root) {
            std::cout << "Empty Tree\n";
            return;
        }
        root->print();
        std::cout << '\n';
    }

    void insert(const T& val) {
        if (!root)
            root = new TreeNode(val);
        else
            root->insert(val);
    }

    bool search(const T& val) {
        if (!root) return false;
        return root->search(val);
    }

    T findMinBST() {
        if (!root) throw std::exception();
        TreeNode* tmp = root;
        while (tmp->left) tmp = tmp->left;
        return tmp->data;
    }

    T findMaxBST() {
        if (!root) throw std::exception();
        TreeNode* tmp = root;
        while (tmp->right) tmp = tmp->right;
        return tmp->data;
    }

    bool isValidBST() {
        if (!root) return true;
        return root->isValidBST(std::numeric_limits<T>::lowest(), std::numeric_limits<T>::max());
    }

    size_t size() {
        if(!root) return 0;
        return root->size();
    }

    T k_smallest(int k) {
        if (!root) throw std::exception();
        if (k <= 0) throw std::exception();
        size_t kk = static_cast<size_t>(k);
        T res = root->k_smallest_helper(kk);
        if (kk != 0) throw std::exception();
        return res;
    }


    void deleteValue(const T& val) {
        root = TreeNode::deleteNode(root, val);
    }

    int countInRange(const T& low, const T& high) {
        return TreeNode::countInRange(root, low, high);
    }

    bool hasPathSum(T sum) {
        return TreeNode::hasPathSum(root, sum);
    }
};

int main() {
    BinarySearchTree<int> t;
    for (int i : {5, 3, 7, 1, 4, 6, 9})
        t.insert(i);

    std::cout << "Initial tree: ";
    t.printInorder();

    t.deleteValue(7);
    std::cout << "After deleting 7: ";
    t.printInorder();

    std::cout << "Count in range [4, 8]: " << t.countInRange(4, 8) << '\n';

    BinarySearchTree<int> t2;
    t2.insert(5);
    t2.insert(4);
    t2.insert(8);
    t2.insert(11);
    t2.insert(7);

    std::cout << "Has path sum 27: " << t2.hasPathSum(27) << '\n';

    return 0;
}

