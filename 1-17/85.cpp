class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int height = matrix.size();
        if (height == 0)
            return 0;
        int width = matrix[0].size();
        if (width == 0)
            return 0;
        vector<int> heights(width);
        int result = 0;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (matrix[i][j] == '0')
                    heights[j] = 0;
                else
                    heights[j]++;
            }
            result = max(result, largestRectangleArea(heights));
        }
        return result;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> left(heights.size()), right(heights.size(),heights.size());
        stack<int> memo;
        for (int i = 0; i < heights.size(); ++i) {
            while (!memo.empty() && heights[memo.top()] > heights[i]) {
                right[memo.top()] = i;
                memo.pop();
            }
            left[i] = memo.empty() ? -1 : memo.top();
            memo.push(i);
        }
        int result = 0;
        for (int i = 0; i < heights.size(); ++i) {
            result = max(result, (right[i]-left[i]-1)*heights[i]);
        }
        return result;
    }
};