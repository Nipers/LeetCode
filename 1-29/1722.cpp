#include<vector>
#include<unordered_set>
#include<map>
using namespace std;
class Solution {
public:
    vector<int> unionSet;
    void merge(int x, int y) {
        unionSet[find(x)] = find(y);
    }
    int find(int x) {
        return x == unionSet[x] ? x : unionSet[x] = find(unionSet[x]);
    }
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int size = source.size();
        unionSet = vector<int>(size);
        for (int i = 0; i < size; i++)
            unionSet[i] = i;
        for (int i = 0; i < allowedSwaps.size(); i++) 
            merge(allowedSwaps[i][0], allowedSwaps[i][1]);//将下标构建并查集
        map<int, unordered_multiset<int>> S;
        for (int i = 0; i < source.size(); i++) {
            S[find(i)].insert(source[i]);
        }
        int ans = 0, father;
        for (int i = 0; i < target.size(); i++) {
            father = find(i);
            if (S[father].find(target[i]) == S[father].end()) {
                ans++;
            }
            else {
                S[father].erase(S[father].find(target[i]));
            }
        }
        return ans;
    }
};