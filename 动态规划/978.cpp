#include<iostream>
#include<unordered_set>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int size = arr.size();
        if (size == 1)
            return 1;
        int res = 1;
        vector<int> len(size);
        len[0] = 1;
        if (arr[1] == arr[0])
            len[1] = 1;
        else {
            len[1] = 2;
            res = 2;
        }
        for (int i = 2; i < size; i++) {
            if (arr[i] == arr[i - 1])
                len[i] = 1;
            else if (arr[i] > arr[i - 1]){
                if (arr[i - 2] >= arr[i - 1])
                    len[i] = len[i - 1] + 1;
                else {
                    len[i] = 2;
                }
            }
            else {
                if (arr[i - 2] <= arr[i - 1])
                    len[i] = len[i - 1] + 1;
                else {
                    len[i] = 2;
                }
            }
            res = res > len[i] ? res : len[i];
        }
        return res;
    }
};