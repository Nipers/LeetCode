#include<vector>
using namespace std;
/* 
维护两个单调队列，一个是最大值，单调递减，一个是最小值，单调递增，但是为什么？
*/
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int max[100000], min[100000], max_left = 0, max_right = 0, min_left = 0, min_right = 0, left = 0, right = 1, ans = 0;
        max[0] = min[0] = nums[0];
        int size = nums.size(), cur;
        while (right < size) {
            cur = nums[right++];
            while (max_right >= max_left && cur > max[max_right]) {
                max_right--;
            }
            while (min_right >= min_left && cur < min[min_right - 1]) {
                min_right--;
            }
            max[++max_right] = min[++min_right] = cur;
            while (max_right >= max_left && min_right >= min_left && max[max_left] - min[min_left] > limit) {
                cur = nums[left];
                if (cur == max[max_left])
                    max_left++;
                if (cur == min[min_left])
                    min_left++;
                left++;
            }
            cur = right - left;
            ans = cur > ans ? cur : ans;
        }
        return ans;
    }
};