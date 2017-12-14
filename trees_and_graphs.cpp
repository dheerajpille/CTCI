#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val = 0;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
    TreeNode(int i) : val{i}, left{nullptr}, right{nullptr} {}
};

void insertLeft(TreeNode* &root, TreeNode* left) {
    root->left = left;
}

void insertRight(TreeNode* &root, TreeNode* right) {
    root->right = right;
}

// 4.5
bool validateBST(TreeNode* root, int min, int max) {
    if (root == nullptr) {
        return true;
    }
    if (root->val < min || root->val > max) {
        return false;
    }
    return validateBST(root->left, -2e9, root->val) && validateBST(root->right, root->val, 2e9);
}

int main(void) {
    TreeNode* a = new TreeNode(4);
    TreeNode* b = new TreeNode(2);
    TreeNode* c = new TreeNode(6);
    TreeNode* d = new TreeNode(1);
    TreeNode* e = new TreeNode(3);
    TreeNode* f = new TreeNode(5);
    insertLeft(a, b);
    insertRight(a, b);
    cout << validateBST(a, -2e9, 2e9) << endl;
    return 0;
}
