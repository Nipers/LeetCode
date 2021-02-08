/* 给你一个二进制字符串数组 strs 和两个整数 m 和 n 。
请你找出并返回 strs 的最大子集的大小，该子集中最多有m个0和n个1 
本题采用二维动态规划，m和n各是一维，转移方程：对于第k个字符串，dp[i][j] = max(dp[i][j], 1 + dp[i - zero[k]][j - one[k]]);
需要注意的地方：需要对字符串进行遍历，由于每个字符串只能用一次，所以必须从大到小进行遍历，
如果从小到大进行遍历的话，毫无疑问一个字符串会被多次使用
*/
#include<iostream>
#include<unordered_set>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size = strs.size();
        vector<int> zero(size, 0), one(size, 0);
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < strs[i].size(); j++) {
                if (strs[i][j] == '0')
                    zero[i]++;
                else
                    one[i]++;
            }
        }
        vector<vector<int>> table(m + 1, vector<int>(n + 1, 0));
        for (int k = 0; k < size; k++) {
            for (int i = m; i >= zero[k]; i--) {
                for (int j = n; j >= one[k]; j--) {
                    table[i][j] = max(table[i][j], 1 + table[i - zero[k]][j - one[k]]);
                }
            }
        }
        return table[m][n];
    }
};