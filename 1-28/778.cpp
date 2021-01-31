#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int size = grid.size();
        bool enough;
        pair<int, int> cur;
        int left = max(grid[0][0], grid[size - 1][size - 1]) - 1, right = size * size - 1, mid = (right + left) >> 1;
        while (left != mid) {
            enough = false;
            queue<pair<int, int>> que;
            que.push(make_pair(0,0));
            vector<vector<int>> visited(size, vector<int>(size, 1));
            visited[0][0] = 0;
            while (!que.empty()) {
                cur = que.front();
                que.pop();
                cur.first++;
                if (cur.first < size)
                    if (grid[cur.first][cur.second] <= mid && visited[cur.first][cur.second]) {
                        if (cur.first == size - 1 && cur.second == size - 1) {
                            enough = true;
                            break;
                        }
                        que.push(cur);
                        visited[cur.first][cur.second] = 0; 
                    }
                cur.first -= 2;
                if (cur.first >= 0)
                    if (grid[cur.first][cur.second] <= mid && visited[cur.first][cur.second]) {
                        que.push(cur);
                        visited[cur.first][cur.second] = 0;
                    }
                cur.first++;
                cur.second++;
                if (cur.second < size)
                    if (grid[cur.first][cur.second] <= mid && visited[cur.first][cur.second]) {
                        if (cur.first == size - 1 && cur.second == size - 1) {
                            enough = true;
                            break;
                        }
                        que.push(cur);
                        visited[cur.first][cur.second] = 0;
                    }
                cur.second -= 2;
                if (cur.second >= 0)
                    if (grid[cur.first][cur.second] <= mid && visited[cur.first][cur.second]) {
                        que.push(cur);
                        visited[cur.first][cur.second] = 0;
                    }
            }
            if (enough)
                right = mid;
            else
                left = mid;
            mid = (left + right) >> 1;
        }
        return right;
    }
};
class Solution {
public:
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool dfs(vector<vector<int>>& grid, vector<vector<int>>& mark, int x, int y, int N, int t) {
        if (x == N-1 && y == N-1) return true;
        for (int i = 0; i < 4; ++i) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if (nx >= 0 && nx < N && ny >= 0 && ny < N && mark[nx][ny] == 0 && grid[nx][ny] <= t) {
                mark[nx][ny] = 1;
                if (dfs(grid, mark, nx, ny, N, t)) {
                    return true;
                }
            }
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int N = grid.size();
        // 0000111
        int l = grid[0][0], r = N * N;
        while (l < r) {
            vector<vector<int>> mark(N, vector<int>(N, 0));
            int mid = (l + r) >> 1;
            if (dfs(grid, mark, 0, 0, N, mid)) r = mid;
            else l = mid + 1;
        } 
        return l;
    }
};