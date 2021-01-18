//思路1，暴力解法，复杂度为n^2。
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int size = heights.size();
        int result = 0;
        if (size == 0)
            return 0;
        for (int i = 0; i < size; i++) {
            int left = i;
            for (left; left >= 0; left--) {
                if (heights[left] < heights[i])
                    break;
            }
            int right = i;
            for (right; right < size; right++) {
                if (heights[right] < heights[i])
                    break;
            }
            int max = (right - left - 1) * heights[i];
            result = result > max ? result : max;
        }
        return result;
    }
};
//思路2：利用单调栈，同时算出左边界和右边界。
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int size = heights.size(), result = 0;
        vector<int> left(size), right(size, size);
        stack<int> stak;
        for (int i = 0; i < size; i++) {
            while(!stak.empty() && heights[stak.top()] >= heights[i]) {
                right[stak.top()] = i;
                stak.pop();
            }
            left[i] = stak.empty() ? -1 : stak.top();
            stak.push(i);
        }
        for (int i = 0; i < size; i++) {
            left[i] = (right[i] - left[i] - 1) * heights[i];
            if (result < left[i]) 
                result = left[i];
        }
        return result;
    }
};