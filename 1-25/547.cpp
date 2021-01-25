#include<vector>
#include<unordered_set>
using namespace std;
class Solution {
public:
    void merge(int i, int j, vector<int>& unionset) {
        unionset[find(j, unionset)] = find(i, unionset);
    }
    int find(int i, vector<int>& unionset) {
        if (unionset[i] == i)
            return i;
        unionset[i] = find(unionset[i], unionset);
        return unionset[i];
    } 
    int findCircleNum(vector<vector<int>>& isConnected) {
        int size = isConnected.size();
        vector<int> unionset(size);
        for (int i = 0; i < size; i++)
            unionset[i] = i;
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++)
                if (isConnected[i][j])
                    merge(i, j, unionset);
        }
        unordered_set<int> roots;
        for (int i = 0; i < size; i++) {
            roots.insert(find(i, unionset));
        }
        return roots.size();
    }
};