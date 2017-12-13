#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// 3.2
class StackMin {
private:
    int minval;
    vector<int> stk;
    vector<int> minstk;

public:
    void push(int);
    void pop();
    int min();
};

void StackMin::push(int i) {
    if (stk.empty() || i < minval) {
        minval = i;
        minstk.push_back(i);
    }
    stk.push_back(i);
}

void StackMin::pop() {
    if (stk.back() == minval) {
        minstk.pop_back();
        minval = minstk.back();
    }
    stk.pop_back();
}

int StackMin::min() {
    return minval;
}

// 3.3
class SetOfStacks {
private:
    int threshold;
    int counter;
    vector<stack<int>> setstk;

public:
    SetOfStacks(int);

    void push(int);
    void pop();
    void popAt(int);
};

SetOfStacks::SetOfStacks(int i) {
    threshold = i;
    counter = 0;
}

void SetOfStacks::push(int i) {
    stack<int> stk;
    int initial = counter;
    if (!setstk.empty()) {
        if (setstk[counter].size() == threshold) {
            counter++;
        } else {
            stk = setstk[counter];
        }
    }
    stk.push(i);
    if (initial == counter && !setstk.empty()) {
        setstk[counter] = stk;
    } else {
        setstk.push_back(stk);
    }
}

void SetOfStacks::pop() {
    setstk[counter].pop();
    if (setstk[counter].empty()) {
        setstk.erase(setstk.begin() + counter);
        counter--;
    }
}

void SetOfStacks::popAt(int i) {
    setstk[i].pop();
}

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

bool MyQueue::empty() {
    return original.empty();
}

int main(void) {
    MyQueue q;
    q.push(1);
    q.push(2);
    q.push(3);
    //cout << q.front() << endl;
    //cout << q.back() << endl;
    //cout << q.size() << endl;
    q.pop();
   // cout << q.front() << endl;
    //cout << q.size() << endl;
    //cout << q.empty() << endl;
    StackMin s;
    s.push(1);
    s.push(3);
    // cout << s.min() << endl;
    s.push(-1);
    // cout << s.min() << endl;
    s.pop();
    // cout << s.min() << endl;
    SetOfStacks ss(2);
    ss.push(1);
    ss.push(2);
    ss.push(3);
    ss.popAt(0);
    return 0;
}
