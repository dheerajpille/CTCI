#include <iostream>
#include <unordered_set>

using namespace std;

struct Node {
    int data = 1;
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

// 2.4
Node* partition(Node* head, int i) {
    Node* left = nullptr;
    Node* right = nullptr;
    while (head) {
        if (head->data < i) {
            if (left == nullptr) {
                left = head;
            }
            left->next = head->next;
            print(left);
        }
        head = head->next;
    }
    return left;
}

// 2.5
int pow(int b, int e) {
    if (e == 0) {
        return 1;
    }
    if (e == 1) {
        return b;
    }
    return b * pow(b, e-1);
}

int sumLists(Node* head1, Node* head2) {
    int value1 = 0, value2= 0;
    int digits = 0;
    while (head1) {
        value1 += head1->data * pow(10, digits);
        digits++;
        head1 = head1->next;
    }
    digits = 0;
    while (head2) {
        value2 += head2->data * pow(10, digits);
        digits++;
        head2 = head2->next;
    }
    return value1+value2;
}

int main(void) {
    Node* head = new Node;
    for (int i = 1; i < 3; i++) {
        insert(head, i);
    }
    print(head);
    cout << sumLists(head, head) << endl;
    return 0;
}
