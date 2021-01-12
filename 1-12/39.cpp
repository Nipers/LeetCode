#include <algorithm>    // std::sort  
#include <vector>       // std::vector
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    int size;
    void calu(vector<int>& candidates, int target, int used, vector<int> old_ans) {
        for (int i = used; i < size; i++) {
            int remain = target - candidates[i];
            if (remain > 0) {
                vector<int> new_ans = old_ans;
                new_ans.push_back(candidates[i]);
                calu(candidates, remain, i, new_ans);
            }
            else if (remain == 0) {
                old_ans.push_back(candidates[i]);
                result.push_back(old_ans);
                return;
            }
            else
                return;
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> x;
        size = candidates.size();
        calu(candidates, target, 0, x);
        return result;
    }
};