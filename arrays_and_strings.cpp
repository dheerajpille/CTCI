#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

// 1.1
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

// 1.2
bool checkPermutation(string str1, string str2) {
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    return str1 == str2;
}

// 1.3
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

// 1.4
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

// 1.5
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

// 1.6
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

// 1.8
vector<vector<int>> zeroMatrix(vector<vector<int>> matrix) {
    vector<vector<int>> original = matrix;
    vector<int> toZero;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            if (matrix[i][j] == 0 && original[i][j] == 0) {
                fill(matrix[i].begin(), matrix[i].end(), 0);
                toZero.emplace_back(j);
            }
        }
    }
    for (int k = 0; k < toZero.size(); k++) {
        for (int l = 0; l < matrix.size(); l++) {
            matrix[l][toZero[k]] = 0;
        }
    }
    return matrix;
}

// 1.9
bool isSubstring(string str1, string str2) {
    if (str1.size() > str2.size()) {
        return isSubstring(str2, str1);
    }
    for (int i = 0; i <= str2.size()-str1.size(); i++) {
        if (str2.substr(i, str1.size()) == str1) {
            return true;
        }
    }
    return false;
}

bool stringRotation(string str1, string str2) {
    string lookup = str1+str1;
    if (str1.size() == str2.size() && str1.size() != 0 && isSubstring(lookup, str2)) {
        return true;
    }
    return false;
}

int main(void) {
    // cout << isUnique("The quick brown fox jumps over the lazy dog") << endl;
    // cout << checkPermutation("anagram", "nagaram") << endl;
    // cout << urlify("Mr John Smith", 13) << endl;
    // cout << palindromePermutation("Tact Coa") << endl;
    // cout << oneAway("pale", "ple") << endl;
    // cout << oneAway("pales", "pale") << endl;
    // cout << oneAway("pale", "bale") << endl;
    // cout << oneAway("pale", "bake") << endl;
    // cout << stringCompression("aabcccccaaa") << endl;
    // cout << isSubstring("string", "substring") << endl;
    // cout << stringRotation("erbottlewat", "waterbottle") << endl;
    return 0;
}
