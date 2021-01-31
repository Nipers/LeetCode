#include<vector>
using namespace std;class UnionSet {
private:
    vector<int> f, sz;
public:
    UnionSet(int n): f(n), sz(n) {
        for (int i = 0; i < n; i++) {
            f[i] = i;
            sz[i] = 1;
        }
    }
    int find(int x) {
        return f[x] == x ? x : f[x] = find(f[x]);
    }
    void merge(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx == fy)
            return;
        f[fx] = fy;
        sz[fy] += sz[fx];
    }
    int size(int x) {
        return sz[find(x)];
    }
};
class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int height = grid.size(), width = grid[0].size();
        int root = height * width;
        UnionSet unionSet(root + 1);
        vector<vector<int>> status = grid;
        for (int i = 0; i < hits.size(); i++) {
            status[hits[i][0]][hits[i][1]] = 0;
        }
        int index;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (status[i][j]) {
                    index = i * width + j;
                    if (!i) 
                        unionSet.merge(index, root);
                    if (i > 0 && status[i - 1][j]) {
                        unionSet.merge(index, index - width);
                    }
                    if (j > 0 && status[i][j - 1]) {
                        unionSet.merge(index, index - 1);
                    }
                }
            }
        }
        int directions[4][2] = {{0, 1},{1, 0},{0, -1},{-1, 0}};
        vector<int> res(hits.size());
        for (int i = hits.size() - 1; i >= 0; i--) {
            int row = hits[i][0], col = hits[i][1];
            if (!grid[row][col])
                continue;
            int prev = unionSet.size(root);
            if (!row) {
                unionSet.merge(col, root);
            }
            index = row * width + col;
            for (int j = 0; j < 4; j++) {
                int x = row + directions[j][0], y = col + directions[j][1];
                if (x >= 0 && x < height && y >= 0 && y < width) {
                    if (status[x][y]) {
                        unionSet.merge(index, x * width + y);
                    }
                }
            }
            res[i] = max(unionSet.size(root) - prev - 1, 0);
            status[row][col] = 1;
        }
        return res;
    }
};