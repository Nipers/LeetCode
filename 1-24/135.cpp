#include<vector>
using namespace std;
class Solution {
public:
    int candy(vector<int>& ratings) {
        int size = ratings.size(), res = 0, right = 1;
        if (!size)
            return 0;
        vector<int> left(size);
        left[0] = 1;
        for (int i = 1; i < size; i++) {
            if (ratings[i] > ratings[i - 1])
                left[i] = left[i - 1] + 1;
            else
                left[i] = 1;
        }
        res += max(right, left[size - 1]);
        for (int i = size - 2; i > -1; i--) {
            if (ratings[i] > ratings[i + 1])
                right++;
            else
                right = 1;
            res += max(left[i], right);
        }
        return res;
    }
};