#include <unordered_map>
#include <vector>
#include <set>
using namespace std;
struct TreeNode {
    int l;
    int r;
    int height;
    TreeNode() {
        l = r = height = 0;
    }
};

class Tree {
private:
    TreeNode* nodes;
public:
    Tree(int size) {
        nodes = new TreeNode[2 * size];
        nodes[0].l = 0;
        nodes[0].r = size - 1;
        int father, left, right, mid;
        for (int i = 1; i < 2 * size - 1; i+=2) {
            father = (i >> 1);
            left = nodes[father].l, right = nodes[father].r;
            mid = (left + right) >> 1;
            nodes[i].l = left;
            nodes[i].r = mid;
            nodes[i + 1].l = mid + 1;
            nodes[i + 1].r = right;
        }
    }
    ~Tree() {
        delete nodes;
    }
    void update(int l, int r, int height, int index) {
        if (nodes[index].l >= l && nodes[index].r <= r) {
            nodes[index].height = nodes[index].height > height ? nodes[index].height : height;
            return;
        }
        if (nodes[index].l == nodes[index].r)
            return;
        if (nodes[index].height != 0) {
            nodes[index << 1].height = nodes[(index << 1) + 1].height = nodes[index].height;
            nodes[index].height = 0;
        }
        update(l, r, height, index << 1);
        update(l, r, height, (index << 1) + 1);
    }
    vector<vector<int>> getAns(int index) {
        vector<vector<int>> ans;
        if (nodes[index].height || nodes[index].l == nodes[index].r) {
            vector<int> temp(2, 0);
            temp[0] = nodes[index].l;
            temp[1] = nodes[index].height;
            ans.push_back(temp);
            return ans;
        }
        ans = getAns(index * 2);
        vector<vector<int>> ans2 = getAns(index * 2 + 1);
        for (auto a : ans2) {
            ans.push_back(a);
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        if (buildings.size() == 0)
            return {};
        unordered_map<int,int> locToIndex;
        vector<int> indexToLoc;
        int num = 0;
        set<int> locs;
        for (auto x : buildings) {
            locs.insert(x[0]);
            locs.insert(x[1]);
        }
        for (int x : locs) {
            indexToLoc.push_back(x);
            locToIndex[x] = num++;
        }
        
    }
}; 