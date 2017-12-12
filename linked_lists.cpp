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
void returnKthToLast(Node* head, int k) {

}

int main(void) {
    Node* head = new Node;
    for (int i = 0; i < 10; i++) {
        insert(head, i);
    }
    for (int i = 0; i < 10; i++) {
        insert(head, i);
    }
    print(head);
    removeDups(head);
    print(head);
    return 0;
}
