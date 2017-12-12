#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <vector>

using namespace std;

bool isUnique(string str) {
    unordered_set<char> lookup;
    for (auto c : str) {
        if (!lookup.count(c)) {
            lookup.insert(c);
        } else {
            return false;
        }
    }
    return true;
}

bool checkPermutation(string str1, string str2) {
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    return str1 == str2;
}

string urlify(string str,int length) {
    const string space = "%20";
    int offset = 0;
    for (int i = 0; i < length; i++) {
        if (str[i+offset] == ' ') {
            str.insert(i+offset, space);
            offset += space.size();
            str.erase(i+offset, 1);
        }
    }
    return str;
}

bool palindromePermutation(string str) {
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    unordered_set<char> lookup;
    for (auto c : str) {
        tolower(c);
        if (!lookup.count(c)) {
            lookup.insert(c);
        } else {
            lookup.erase(c);
        }
    }
    return lookup.size() == 0 || lookup.size() == 1;
}

bool oneAway(string str1, string str2) {
    if (str1.size() > str2.size()) {
        return oneAway(str2, str1);
    }
    int changes = 0, offset = 0;
    if (str1.size() == str2.size()) {
        for (int i = 0; i < str1.size(); i++) {
            if (str1[i] != str2[i]) {
                changes++;
            }
        }
    } else {
        for (int i = 0; i < str1.size(); i++) {
            while (str1[i] != str2[i+offset]) {
                offset++;
                changes++;
                if (changes > 1) {
                    break;
                }
            }
        }
    }
    return changes == 0 || changes == 1;
}

string stringCompression(string str) {
    string result;
    int counter = 0;
    char curr = str[0];
    for (auto c : str) {
        if (c == curr) {
            counter++;
        } else {
            result += curr + to_string(counter);
            curr = c;
            counter = 1;
        }
    }
    result += curr + to_string(counter);
    if (result.size() > str.size()) {
        return str;
    }
    return result;
}

int main(void) {
    // cout << stringCompression("aabcccccaaa") << endl;
    return 0;
}
