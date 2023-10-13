#include <iostream>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    BinaryTree() : root(nullptr) {}

    void insert(int val) {
        root = insertRecursive(root, val);
    }

    bool search(int val) {
        return searchRecursive(root, val);
    }

    void inorderTraversal() {
        inorderRecursive(root);
        std::cout << std::endl;
    }

private:
    TreeNode* root;

    TreeNode* insertRecursive(TreeNode* current, int val) {
        if (current == nullptr) {
            return new TreeNode(val);
        }

        if (val < current->data) {
            current->left = insertRecursive(current->left, val);
        } else if (val > current->data) {
            current->right = insertRecursive(current->right, val);
        }

        return current;
    }

    bool searchRecursive(TreeNode* current, int val) {
        if (current == nullptr) {
            return false;
        }

        if (current->data == val) {
            return true;
        }

        if (val < current->data) {
            return searchRecursive(current->left, val);
        } else {
            return searchRecursive(current->right, val);
        }
    }

    void inorderRecursive(TreeNode* current) {
        if (current == nullptr) {
            return;
        }

        inorderRecursive(current->left);
        std::cout << current->data << " ";
        inorderRecursive(current->right);
    }
};

int main() {
    BinaryTree tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    tree.inorderTraversal(); // Should print the sorted order of the tree nodes.

    std::cout << "Search for 30: " << (tree.search(30) ? "Found" : "Not Found") << std::endl;
    std::cout << "Search for 90: " << (tree.search(90) ? "Found" : "Not Found") << std::endl;

    return 0;
}
