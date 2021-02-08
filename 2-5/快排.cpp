#include<vector>
using namespace std;
class Solution {
public:
    void quickSort(vector<int> &nums, int left, int right) {
        if (left < right) {
            int pivot = nums[left], low = left, high = right;
            while (low < high) {
                while (low < high && nums[high] >= pivot){
                    high--;
                }
                nums[low] = nums[high];
                while (low < high && nums[low] <= pivot){
                    low++;
                }
                nums[high] = nums[low];
            }
            nums[low] = pivot;
            quickSort(nums, left, low - 1);
            quickSort(nums, low + 1, right);
        }        
    }
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};