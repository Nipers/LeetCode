#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        int size1 = candiesCount.size(), size2 = queries.size();
        vector<long long> prefix (size1);
        prefix[0] = candiesCount[0];
        for (int i = 1; i <= size1; i++) {
            prefix[i] = prefix[i - 1] + candiesCount[i];
        }
        vector<bool> ans(size2); 
        long long type, day, cap;
        for (int i = 0; i < size2; i++) {
            type = queries[i][0], day = queries[i][1], cap = queries[i][2];
            if (prefix[type] < day)
                ans[i] = false;
            if (prefix[type - 1] > (day - 1) * cap)
                ans[i] = false;
            ans[i] = true;
        }
        cout << "42: " << prefix[42] <<endl;
        cout << "43: " << prefix[43] <<endl;
        return ans;
    }
};