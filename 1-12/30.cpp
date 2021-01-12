#include <vector>
#include <string>
#include <unordered_map>
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