#include<vector>
using namespace std;
/* 
维护两个单调队列，一个是最大值，单调递减，一个是最小值，单调递增
最大值队列中存储的是当前序列中最大值元素之后的单调最大序列
最小值队列中存储的事当前序列中最小值元素之后的单调最小序列
所以序列尾端右移时总是检查是否和队列头部相同，相同则弹出。
这两个队列中的对象是当前窗口中的数
最大值序列必须是单调递减的，否则无法保证弹出之后头部仍为最大值，由于从左到右进行遍历，单调队列中的元素也必须按原序列中的顺序进行存储
单调队列的新理解：如果有人比你强还比你年轻，你就该走了。
*/
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int max[100000], min[100000], max_left = 0, max_right = 0, min_left = 0, min_right = 0, left = 0, right = 1, ans = 1;
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
//也可以用简单的map，heap等数据结构解这道题。
