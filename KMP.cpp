#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
// vector<int> getNext(string source) {
//     vector<int> next(source.size());
//     int copyed = -1, i = 0;
//     next[0] = -1;
//     while (i < source.size()) {
//         if (copyed == -1 || source[copyed] == source[i]) {
//             copyed++, i++;
//             next[i] = copyed;
//         }
//         else {
//             copyed = next[copyed];
//         }
//     }
//     return next;
// }

// int KMP(string source, string pattern) {
//     vector<int> next = getNext(pattern);
//     int i = 0, j = 0;
//     while (i < source.size() && j < pattern.size()) {
//         if (j == -1 || source[i] == pattern[j]) {
//             i++, j++;
//         }
//         else {
//             j = next[j];
//         }
//         if (j == pattern.size())
//             return i - j;
//         return -1;
//     }
// }

vector<int> getNext(string source) {
    vector<int> next(source.size());
    int copyed = -1, i = 0;
    next[0] = -1;
    while (i < source.size()) {
        if (copyed == -1 || source[copyed] == source[i]) {
            copyed++, i++;
            next[i] = copyed;
        }
        else {
            copyed = next[copyed];
        }
    }
    return next;
}

int KMP() {
    string pattern = "ABCDABD", source = "ABDDABCDABD";
    vector<int> next = getNext(pattern);
    for (int i : next) {
        cout << i << endl;
    }
    int i = 0, j = 0;
    while (i < source.size() && j < pattern.size()) {
        if (j < 0 || source[i] == pattern[j]) {
            i++, j++;
        }
        else {
            j = next[j];
        }
    }
    if (j == pattern.size())
        return i - j;
    return -1;
}
int main() {
    cout << KMP();
}