#include <vector>
#include <string>
#include <unordered_map>
#include <string.h>
using namespace std;
/*复杂度为n*m的版本*/
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int size = s.length(), num = words.size();
        vector<int> result;
        if (size == 0 || num == 0)
            return result;
        int width = words[0].length(), length = width * num;
        if (width == 0) 
            return result;
        unordered_map<string, int> info;
        for (string& word : words) 
            info[word]++;
        for (int offset = 0; offset < width; offset++) {
            int right = 0;
            unordered_map<string, int> window;
            for (int left = offset; left + width <= size; left += width) {
                if (left - offset >= length) {
                    string out = s.substr(left - length, width);
                    window[out]--;
                    if (info[out] > window[out])
                        right--;
                }
                string in = s.substr(left, width);
                window[in]++;
                if (window[in] <= info[in]) {
                    right++;
                }
                if (right == num) 
                    result.push_back(left - length + width);
            }
        } 
        return result;
    }
};

typedef unsigned long long Ull;
class Solution {
    int base = 19;//哈希函数的base
public:
    Ull getHash(Ull hash[], Ull modulus[], int l, int r) {//得到l和r之间字符串的hash值
        return hash[r] - hash[l - 1] * modulus[r - l + 1];
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        int size = s.length(), num = words.size();
        vector<int> result;
        if (size == 0 || num == 0)
            return result;
        int width = words[0].length(), length = width * num;
        if (width == 0) 
            return result;
        s = ' ' + s;//加上一个空格占位，结果不变
        Ull hash[size + 1], modulus[size + 1];
        memset(hash, 0, sizeof hash);
        modulus[0] = 1;
        for (int i = 1; i <= size; i++) {
            hash[i] = hash[i - 1] * base + s[i] - 96;
            modulus[i] = modulus[i - 1] * base;
        }
        unordered_map<Ull, int> info;
        for (string& word : words) {
            Ull value = 0;
            for (auto c : word) {
                value = value * base + c - 96;
            }
            info[value]++;
        }
        for (int offset = 1; offset <= width; offset++) {
            int right = 0;
            unordered_map<Ull, int> window;
            for (int left = offset; left + width <= size + 1; left += width) {
                if (left - offset >= length) {
                    Ull out = getHash(hash, modulus, left - length, left - length + width - 1);
                    window[out]--;
                    if (info[out] > window[out])
                        right--;
                }
                Ull in = getHash(hash, modulus, left, left + width - 1);
                window[in]++;
                if (window[in] <= info[in]) {
                    right++;
                }
                if (right == num) 
                    result.push_back(left - length + width - 1);
            }
        } 
        return result;
    }
};