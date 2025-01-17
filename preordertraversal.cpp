#include <iostream>
#include <vector>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void PreOrder(TreeNode* root, std::vector<int>& res) {
        if (root == nullptr) return;
        res.push_back(root->val);
        PreOrder(root->left, res);
        PreOrder(root->right, res);
    }

    std::vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> res;
        PreOrder(root, res);
        return res;
    }
};

int main() {
    // Example usage: Construct a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution sol;
    std::vector<int> preorder = sol.preorderTraversal(root);

    std::cout << "Preorder Traversal: ";
    for (int val : preorder) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Clean up memory (important to prevent memory leaks)
    delete root->right->left;
    delete root->right;
    delete root;

    // Example with empty tree
    std::vector<int> preorder_empty = sol.preorderTraversal(nullptr);
    std::cout << "Preorder Traversal of Empty Tree: ";
    for (int val : preorder_empty) {
        std::cout << val << " ";
    }
    std::cout << std::endl;


    //Example with single node tree
    TreeNode* root2 = new TreeNode(5);
     std::vector<int> preorder_single = sol.preorderTraversal(root2);
    std::cout << "Preorder Traversal of Single Node Tree: ";
    for (int val : preorder_single) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    delete root2;

    return 0;
}