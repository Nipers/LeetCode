#include<iostream>
#include<unordered_set>
#include<vector>
#include<string>
using namespace std;
/*
解法1：动态规划，
每个点考虑它前面的比它小的节点，然后一次遍历求最长的，
从前向后遍历保证结果正确*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> num(nums.size(), 1);
        int max;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    max = 1 + num[j];
                    num[i] = num[i] > max ? num[i] : max;
                }

            }
        }
        max = 0;
        for (int i = 0; i < nums.size(); i++) {
            max = max > num[i] ? max : num[i];
        }
        return max;
    }
};
/*
解法2：贪心算法+二分查找，维护一个数组k，k[l]的值为长度为l+1的递增数组的最后一个元素值，
从前向后利用二分法不断更新这个数组，由于前面的值不会再次被加入数组中，将序列值更新对于先前的结果不会有影响。
*/
class Solution2 {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> num(nums.size());
        int size = 0, left, mid, right;
        num[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (num[size] < nums[i])
                num[++size] = nums[i];
            else {
                if (num[0] > nums[i])
                    num[0] = nums[i];
                else if (size == 1)
                    num[1] = nums[i] > num[0] ? nums[i] : num[1];
                else {
                    left = 0, right = size, mid = (left + right) >> 1;
                    while (left + 1 < right) {
                        if (num[mid] > nums[i]) 
                            right = mid;
                        else if (num[mid] < nums[i]) 
                            left = mid;
                        else {
                            right = mid;
                            break;
                        }
                        mid = (left + right) >> 1;
                    }
                    num[right] = nums[i];
                }
                
            }
        }
        return size + 1;
    }
};