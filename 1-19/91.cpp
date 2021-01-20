#include<string>
using namespace std;
class Solution {
public:
    int numDecodings(string s) {
        if (s.length() == 0)
            return 0;
        if (s[0] == '0')
            return 0;
        int pre = 1, cur = 1, rec = 1, size = s.length();
        for (int i = 1; i < size; i++) {
            rec = cur;
            if (s[i] == '0') {
                if(s[i - 1] > '2' || s[i - 1] == '0')
                    return 0;
                cur = pre;
            }
            else {
                if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] < '7'))
                    cur += pre;
            }
            pre = rec;
        }
        return cur;
    }
};

