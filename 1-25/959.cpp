#include<vector>
#include<string>
#include<queue>
#include<unordered_set>
using namespace std;
class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int size = grid.size() * 3, i, j, index1, index2 = 0;
        vector<vector<int>> table(size, vector<int>(size, 0));
        for (i = 0; i < grid.size(); i++) {
            j = index1 = 0;
            while (j < grid[i].size()) {
                if (grid[i][j] == 92)
                    table[index2 + 2][index1 + 2] = table[index2 + 1][index1 + 1] = table[index2][index1] = 1;
                if (grid[i][j] == 47)
                    table[index2 + 2][index1] = table[index2 + 1][index1 + 1] = table[index2][index1 + 2] = 1;
                j++;
                index1 += 3;
            }
            index2 += 3;
        }
        index1 = 0;
        queue<pair<int,int>> que;
        pair<int, int> cur;
        for (i = 0; i < size; i++) {
            for (j = 0; j < size; j++) {
                if (!table[i][j]) {
                    index1++;
                    que.push(make_pair(i, j));
                    while (!que.empty()) {
                        cur = que.front();
                        que.pop();
                        cur.first++;
                        if (cur.first < size)
                            if (!table[cur.first][cur.second]) {
                                table[cur.first][cur.second] = 1;
                                que.push(cur);
                            }                                
                        cur.first -= 2;
                        if (cur.first > -1)
                            if (!table[cur.first][cur.second]) {
                                table[cur.first][cur.second] = 1;
                                que.push(cur);
                            }  
                        cur.first++;
                        cur.second++;
                        if (cur.second < size)
                            if (!table[cur.first][cur.second]) {
                                table[cur.first][cur.second] = 1;
                                que.push(cur);
                            }  
                        cur.second -= 2;
                        if (cur.second > -1)
                            if (!table[cur.first][cur.second]) {
                                table[cur.first][cur.second] = 1;
                                que.push(cur);
                            }  
                    }
                }
            }
        }
        return index1;
    }
};
class Solution {
public:
    int find(vector<int>& f, int x) {
        if (f[x] == x)
            return x;
        f[x] = find(f, f[x]);
        return f[x];
    }
    void merge(vector<int>& f, int x, int y) {
        f[find(f, x)] = find(f, y);
    }
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size(), idx = 0, size = n * n * 4, i, j;
        vector<int> f(size);
        for (i = 0; i < size; i++)
            f[i] = i;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (i < n - 1) {
                    merge(f, idx + 2, idx + (n << 2));
                }
                if (j < n - 1) {
                    merge(f, idx + 1, idx + 7);
                }
                if (grid[i][j] == '/') {
                    merge(f, idx, idx + 3);
                    merge(f, idx + 1, idx + 2);
                } else if (grid[i][j] == '\\') {
                    merge(f, idx, idx + 1);
                    merge(f, idx + 2, idx + 3);
                } else {
                    merge(f, idx, idx + 1);
                    merge(f, idx + 1, idx + 2);
                    merge(f, idx + 2, idx + 3);
                }
                idx+=4;
            }
        }
        unordered_set<int> fathers;
        for (i = 0; i < size; i++)
            fathers.insert(find(f, i));
        return fathers.size();
    }
};