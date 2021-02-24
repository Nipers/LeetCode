/* 有一根长度为 n 个单位的木棍，棍上从 0 到 n 标记了若干位置。例如，长度为 6 的棍子可以标记如下：
给你一个整数数组 cuts ，其中 cuts[i] 表示你需要将棍子切开的位置。
你可以按顺序完成切割，也可以根据需要更改切割的顺序。
每次切割的成本都是当前要切割的棍子的长度，切棍子的总成本是历次切割成本的总和。对棍子进行切割将
会把一根木棍分成两根较小的木棍（这两根木棍的长度和就是切割前木棍的长度）。请参阅第一个示例以获得更直观的解释。
返回切棍子的 最小总成本 。

 */
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int size = cuts.size();
        sort(cuts.begin(), cuts.end());
        cuts.push_back(n);
        //cuts[j] - cuts[i]:合成i~j之后的代价
        int *vals = new int[size + 1];
        vals[0] = cuts[0];//vals里存储着所有段的长度
        for (int i = 1; i < size; i++) {
            vals[i] = cuts[i] - cuts[i - 1];
        }
        vals[size] = n - cuts[size - 1];
        int ** dp = new int*[size + 1];
        for (int i = 0; i <= size; i++) {
            dp[i] = new int[size + 1];
            for (int j = i; j < size + 1; j++) {
                dp[i][j] = 0;//dp[i][j]代表从i到j进行合成之后的最小cost
            }
        }
        dp[0][1] = cuts[1];
        for (int i = 1; i < size; i++) {
            dp[i][i + 1] = cuts[i + 1] - cuts[i - 1];
        }
        int length, y;
        for (int k = 2; k <= size; k++) {
            for (int i = 0; i <= size - k; i++) {
                y = i + k;
                if (i == 0)
                    length = cuts[y];
                else
                    length = cuts[y] - cuts[i - 1];
                for (int j = i; j < y; j++) {
                    if (dp[i][y] != 0) {
                        dp[i][y] = min(dp[i][j] + dp[j + 1][y] + length, dp[i][y]);
                    }
                    else
                        dp[i][y] = dp[i][j] + dp[j + 1][y] + length;
                }
            }
        }
        return dp[0][size];
    }
};