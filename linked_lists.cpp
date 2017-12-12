#include <iostream>
#include <unordered_set>

using namespace std;

struct Node {
    int data = 0;
    Node* next = nullptr;
};

void insert(Node* &head, int data) {
    Node* newNode = new Node;
    newNode->data = data;
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

// 2.1
void removeDups(Node* head) {
    unordered_set<int> lookup;
    if (head == nullptr || head->next == nullptr) {
        return;
    }
    Node* prev = head;
    while (head) {
        if (lookup.count(head->data)) {
            prev->next = head->next;
        } else {
            lookup.insert(head->data);
            prev = head;
        }
        head = head->next;
    }
}

// 2.2
Node* returnKthToLast(Node* head, int k) {
    if (head == nullptr) {
        return head;
    }
    int i = 0;
    Node* ptr = head;
    while (ptr) {
        ptr = ptr->next;
        i++;
    }
    if (i < k) {
        return nullptr;
    }
    while (head) {
        if (i-k == 0) {
            break;
        }
        head = head->next;
        i--;
    }
    return head;
}

// 2.3
void deleteMiddleNode(Node* head) {
    if (head == nullptr) {
        return;
    }
    Node* nextNode = head->next;
    head->data = nextNode->data;
    head->next = nextNode->next;
    delete nextNode;
}

Node* partition(Node* head, int i) {

}

int main(void) {
    Node* head = new Node;
    for (int i = 0; i < 10; i++) {
        insert(head, i);
    }
    print(head);
    deleteMiddleNode(head);
    print(head);
    return 0;
}
