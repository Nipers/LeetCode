#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length(), n = s2.length(), o = s3.length();
        if (m + n != o)
            return false;
        vector<vector<int>> table(m + 1, vector<int>(n + 1, 0));
        table[0][0] = 1;
        s1 = " " + s1;
        s2 = " " + s2;
        s3 = " " + s3;
        int i, j, p;
        for (i = 0; i <= m; i++) {
            for (j = 0; j <= n; j++) {
                p = i + j;
                if (i > 0) {
                    table[i][j] |= (table[i - 1][j] && s1[i] == s3[p]);
                }
                if (j > 0) {                    
                    table[i][j] |= (table[i][j - 1] && s2[j] == s3[p]);
                }
            }
        }
        return table[m][n];
    }
};

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length(), n = s2.length(), o = s3.length();
        if (m + n != o)
            return false;
        vector<vector<int>> table(2, vector<int>(n + 1, 0));
        table[0][0] = 1;
        s1 = " " + s1;
        s2 = " " + s2;
        s3 = " " + s3;
        int i, j, p;
        for (i = 0; i <= m; i++) {
            for (j = 0; j <= n; j++) {
                if (i)
                    table[i & 1][j] = 0;
                p = i + j;
                if (i > 0) {
                    table[i & 1][j] |= (table[1 - (i & 1)][j] && s1[i] == s3[p]);
                }
                if (j > 0) {                    
                    table[i & 1][j] |= (table[i & 1][j - 1] && s2[j] == s3[p]);
                }
            }
        }
        return table[m & 1][n];
    }
};