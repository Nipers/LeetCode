#include<vector>
using namespace std;
/* 
有 n 个气球，编号为0 到 n - 1，每个气球上都标有一个数字，这些数字存在数组 nums 中。现在要求你戳破所有的气球。
戳破第 i 个气球，你可以获得 nums[i - 1] * nums[i] * nums[i + 1] 枚硬币。
这里的 i - 1 和 i + 1 代表和 i 相邻的两个气球的序号。如果 i - 1或 i + 1 超出了数组的边界，那么就当它是一个数字为 1 的气球。
求所能获得硬币的最大数量。

思路：一看有个一维数组，而且需要选择最佳的方法，所以考虑动态规划
dp[i][j]表示从i到j，可获得的最大硬币数，那么，dp[i][i]就是单独戳破一个气球可获得的硬币数，dp[i][j]则需要决定哪个气球先被戳破
然后剩下的气球作为两段分别戳破，遍历所有的气球作为第一个被戳破的，获得dp[i][j]的值
这个思路存在的问题在于，在i和j之间先戳破了一个k之后，剩下的值不再是dp[i][k - 1]和dp[k + 1][j]，考虑先戳哪一个，就会不断变化，无法进行计算
但大体思路是对的，所以应该改变思路，把k作为最后一个戳破的气球，这样它始终作为分界线将两边的气球分开，就可以进行遍历，而最后一个戳破的气球
获得的硬币数就是val[i - 1] * val[k] * val[j + 1];
 */
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int size = nums.size();
        if (size == 1)
            return nums[0];
        int * N = new int[size + 2];
        int ** dp = new int*[size + 2];
        N[0] = N[size + 1] = 1;
        int i, j, k, sum;
        for (i = 1; i <= size; i++) {
            N[i] = nums[i - 1];
        }
        for (i = 0; i < size + 2; i++) {
            dp[i] = new int[size + 2];
            for (j = 0; j < size + 2; j++) {
                dp[i][j] = 0;
            }
        }
        for (i = size - 1; i >= 0; i--) {
            for (j = i + 2; j <= size + 1; j++) {
                for (k = i + 1; k < j; k++) {
                    sum = N[i] * N[k] * N[j];
                    sum += dp[i][k] + dp[k][j];
                    dp[i][j] = dp[i][j] > sum ? dp[i][j] : sum;
                }
            }
        }
        return dp[0][size + 1];
    }
};