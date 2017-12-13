#include <iostream>
#include <stack>

using namespace std;

// 3.4
class MyQueue {
private:
    stack<int> original;
    stack<int> reversed;

public:
    int size();
    int front();
    int back();
    void push(int);
    void pop();
    bool empty();
};

int MyQueue::size() {
    int counter = 0;
    while (!original.empty()) {
        counter++;
        reversed.push(original.top());
        original.pop();
    }
    while (!reversed.empty()) {
        original.push(reversed.top());
        reversed.pop();
    }
    return counter;
}

int MyQueue::front() {
    int front;
    while (!original.empty()) {
        reversed.push(original.top());
        original.pop();
    }
    front = reversed.top();
    while (!reversed.empty()) {
        original.push(reversed.top());
        reversed.pop();
    }
    return front;
}

int MyQueue::back() {
    return original.top();
}

void MyQueue::push(int i) {
    original.push(i);
}

void MyQueue::pop() {
    while (!original.empty()) {
        reversed.push(original.top());
        original.pop();
    }
    reversed.pop();
    while (!reversed.empty()) {
        original.push(reversed.top());
        reversed.pop();
    }
}

int main(void) {
    MyQueue q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << q.front() << endl;
    cout << q.back() << endl;
    cout << q.size() << endl;
    q.pop();
    cout << q.front() << endl;
    cout << q.size() << endl;
    return 0;
}
