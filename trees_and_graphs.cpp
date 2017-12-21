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

void print(TreeNode* root)
{
    if (root == nullptr)
        return;
    print(root->left);
    cout << root->val << " ";
    print(root->right);
}

// 4.2
TreeNode* minimalTree(vector<int> vec, int low, int high) {
    if (low > high) {
        return nullptr;
    }
    int mid = (low+high)/2;
    TreeNode* newNode = new TreeNode(vec[mid]);
    newNode->left = minimalTree(vec, low, mid-1);
    newNode->right = minimalTree(vec, mid+1, high);
    return newNode;
}

TreeNode* minimalTree(vector<int> vec) {
    if (vec.size() == 0) {
        return nullptr;
    }
    return minimalTree(vec, 0, vec.size()-1);
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
    insertLeft(b, d);
    insertRight(b, e);
    insertLeft(c, f);
    insertLeft(a, b);
    insertRight(a, c);
    //cout << validateBST(a, -2e9, 2e9) << endl;
    vector<int> arr = {1,2,3,4,5,6,7,8};
    TreeNode* root = minimalTree(arr);
    print(root);
    return 0;
}
