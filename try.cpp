#include<iostream>
#include<unordered_set>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0, right = 0, max = 1, sum = nums[0];
        int distance = 0;
        while (right < nums.size() - 1) {
            right++;
            sum += nums[right];
            distance = nums[right] * (right - left + 1) - sum;
            while (distance > k) {
                sum -= nums[left];
                distance -= (nums[right] - nums[left]);
                left++;
            }
            max = max > (right - left + 1) ? max : (right - left + 1);
        }
        return max;
    }
};