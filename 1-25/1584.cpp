//prim算法：随机选取一个点进入连通集，然后将离它最近的节点入集，然后将离连通集最近的节点入集。
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int size = points.size();
        int distance[size];
        int added[size];
        for (int i = 0; i < size; i++)
            added[i] = 0;
        int cur = 0, dis;
        added[0] = 1;
        for (int i = 1; i < size; i++) {
            dis = 0;
            if (points[i][0] > points[cur][0])
                dis += points[i][0] - points[cur][0];
            else
                dis += points[cur][0] - points[i][0];
            if (points[i][1] > points[cur][1])
                dis += points[i][1] - points[cur][1];
            else
                dis += points[cur][1] - points[i][1];
            distance[i] = dis;
        }
        int mini, res = 0;
        for (int i = 1; i < size; i++) {
            mini = 0xffffffff;
            for (int j = 0; j < size; j++) {
                if (!added[j]) {
                    if (distance[j] < mini) {
                        cur = j;
                        mini = distance[j];
                    }
                }
            }
            res += mini;
            added[cur] = 1;
            for (int j = 0; j < size; j++) {
                if (!added[j]) {
                    dis = 0;
                    if (points[j][0] > points[cur][0])
                        dis += points[j][0] - points[cur][0];
                    else
                        dis += points[cur][0] - points[j][0];
                    if (points[j][1] > points[cur][1])
                        dis += points[j][1] - points[cur][1];
                    else
                        dis += points[cur][1] - points[j][1];
                    distance[j] = distance[j] > dis ? dis : distance[j];
                }

            }
        }
        return res;
    }
};

//Kruskal 算法
//将所有的边排好序，从短边到长边依次加入树中，确保不形成回路，
class Solution2 {
public:
    struct edge {
        int x, y, dis;
        edge(int x, int y, int dis) : x(x), y(y), dis(dis) {}
    };
    void merge(int x, int y, vector<int>& unionSet) {
        unionSet[find(x, unionSet)] = find(y, unionSet); 
    }
    int find(int x, vector<int>& unionSet) {
        return unionSet[x] == x ? x : unionSet[x] = find(unionSet[x], unionSet);
    } 
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<edge> edges;
        int size = points.size();
        int dis;
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                dis = 0;
                if (points[i][0] > points[j][0])
                    dis += points[i][0] - points[j][0];
                else
                    dis += points[j][0] - points[i][0];
                if (points[i][1] > points[j][1])
                    dis += points[i][1] - points[j][1];
                else
                    dis += points[j][1] - points[i][1];
                edges.emplace_back(i, j, dis);
            }
        }
        sort(edges.begin(), edges.end(), [](edge a, edge b) -> int { return a.dis < b.dis; });
        vector<int> unionSet(size);
        for (int i = 0; i < size; i++)
            unionSet[i] = i;
        int res = 0, done = 1;
        for (edge i : edges) {
            if (find(i.x, unionSet) != find(i.y, unionSet)) {
                res += i.dis;
                done++;
                merge(i.x, i.y, unionSet);
            }
            if (done == size)
                break;
        }
        return res;  
    }
};