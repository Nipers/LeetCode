#include<vector>
using namespace std;
class Solution {
public:
    int MODULO = 1000000007;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> prefixSums = vector<int>(n + 1);
        prefixSums[0] = 0;
        for (int i = 0; i < n; i++) {
            prefixSums[i + 1] = prefixSums[i] + nums[i];
        }
        vector<int> prefixPrefixSums = vector<int>(n + 1);
        prefixPrefixSums[0] = 0;
        for (int i = 0; i < n; i++) {
            prefixPrefixSums[i + 1] = prefixPrefixSums[i] + prefixSums[i + 1];
        }//准备好前缀和和前缀和的前缀和
        //getsum函数的作用应该是得到最小的n个数的和
        return (getSum(prefixSums, prefixPrefixSums, n, right) - getSum(prefixSums, prefixPrefixSums, n, left - 1)) % MODULO;
    }

    int getSum(vector<int>& prefixSums, vector<int>& prefixPrefixSums, int n, int k) {
        int num = getKth(prefixSums, n, k);
        int sum = 0;
        int count = 0;
        for (int i = 0, j = 1; i < n; i++) {
            while (j <= n && prefixSums[j] - prefixSums[i] < num) {
                j++;
            }
            j--;
            sum += prefixPrefixSums[j] - prefixPrefixSums[i] - prefixSums[i] * (j - i);
            sum %= MODULO;
            count += j - i;
        }
        sum += num * (k - count);
        return sum;
    }

    int getKth(vector<int>& prefixSums, int n, int k) {//根据前缀和得到第k个数的大小？二分法
        int low = 0, high = prefixSums[n];//high是所有数中最大的
        while (low < high) {
            int mid = (high - low) / 2 + low;
            int count = getCount(prefixSums, n, mid);
            if (count < k) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }

    int getCount(vector<int>& prefixSums, int n, int x) {//精髓
        int count = 0;
        for (int i = 0, j = 1; i < n; i++) {
            while (j <= n && prefixSums[j] - prefixSums[i] <= x) {
                j++;
            }
            j--;
            count += j - i;
        }
        return count;
    }
};