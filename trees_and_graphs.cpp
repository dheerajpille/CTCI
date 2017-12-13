#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val = 0;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
    TreeNode(int i) : val{i}, left{nullptr}, right{nullptr} {}
};

struct Node {
    int data = 0;
    Node* next = nullptr;
    Node(int i) : data{i}, next{nullptr} {}
};

void insert(Node* &head, int data) {
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void print(Node* head) {
    while (head) {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

// 4.2
TreeNode* minimalTree(vector<int> vec) {
    int size = vec.size();
    if (vec.size() == 0) {
        Node*
    }
}

int main(void) {
    vector<int> vec = {1,2,3,4,5,6,7,8,9};
    return 0;
}
