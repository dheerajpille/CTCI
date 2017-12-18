#include <iostream>

using namespace std;

int numberSwapper(int& x, int& y) {
    x = x + y;
    y = x - y;
    x = x - y;
}

int main(void) {
    return 0;
}
