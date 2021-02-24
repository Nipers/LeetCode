#include<vector>
using namespace std;
/* 
数组求区域和，很有可能需要用到前缀和以及容斥原理
 */
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int m = mat.size(), n = mat[0].size(), i, j, a, b, c, d;
        for (i = 0; i < m; i++) {
            for (j = 1; j < n; j++) {
                mat[i][j] += mat[i][j - 1];
            }
        }
        for (i = 1; i < m; i++) {
            for (j = 0; j < n; j++) {
                mat[i][j] += mat[i - 1][j];
            }
        }
        vector<vector<int>> ans(m, vector<int>(n));
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                a = min(i + K, m - 1), b = min(j + K, n - 1);
                c = i - K - 1, d = j - K - 1;
                ans[i][j] = mat[a][b];
                if (c >= 0)
                    ans[i][j] -= mat[c][b];
                if (d >= 0)
                    ans[i][j] -= mat[a][d];
                if (c >= 0 && d >= 0)
                    ans[i][j] += mat[c][d];
                
            }
        }
        return ans;
    }
};