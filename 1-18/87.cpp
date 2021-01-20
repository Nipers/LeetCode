#include <string>
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.length() != s2.length())
            return false;
        if (s1 == s2)
            return true;
        int *table = new int[26];
        for (int i = 0; i < 26; i++)
            table[i] = 0;
        for (int i = 0; i < s1.length(); i++) {
            table[s1[i] - 'a']++;
            table[s2[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (table[i] != 0) {
                delete []table;
                return false;
            }
        }
        delete []table;
        for (int i = 1; i < s1.length(); i++) {
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i, s1.length() - i), s2.substr(i, s2.length() - i)))
                return true;
            if (isScramble(s1.substr(i, s1.length() - i), s2.substr(0, s2.length() - i)) && 
                isScramble(s1.substr(0, i), s2.substr(s2.length() - i, i))
                )
                return true;
        }
        return false;
    }
};