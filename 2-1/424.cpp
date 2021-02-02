#include<string>
using namespace std;
class Solution {
public:
    int characterReplacement(string s, int k) {
        int size = s.size();
        if (size < 2) 
            return size;
        int left = 0, table[26] = {0}, max, right = 0, charToInt;
        for (right = 0; right < size; right++) {
            charToInt = s[right] - 'A';
            table[charToInt]++;
            if (table[charToInt] > max)
                max = table[charToInt];
            if (right - left + 1 > max + k) {
                table[s[left] - 'A']--;
                left++;
            }            
        }
        return size - left;
    }
};