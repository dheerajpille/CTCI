#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 16.1
int numberSwapper(int& x, int& y) {
    x = x + y;
    y = x - y;
    x = x - y;
}

// 16.2
int wordFrequencies(string word, vector<string> book) {
    int counter = 0;
    string check = "";
    for (auto c : word) {
        tolower(c);
    }
    for (auto words : book) {
        check = "";
        for (auto c : words) {
            check += tolower(c);
        }
        if (word == check) {
            counter++;
        }
    }
    return counter;
}

int main(void) {
    vector<string> book = {"lOl", "I", "LOl"};
    string word = "lol";
    cout << wordFrequencies(word, book) << endl;
    return 0;
}
