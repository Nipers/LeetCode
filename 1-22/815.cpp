#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<queue>
using namespace std;
class Solution {
public:
    vector<unordered_set<int>> Set;
    bool check(int i, int j, vector<vector<int>> &temp) {
        if (temp[i].size() > temp[j].size()) {
            return check(j, i, temp);
        }
        for (auto& num : temp[i]) {
            if (Set[j].count(num))
                return true;
        }
        return false;
    }
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if (S == T)
            return 0;
        int size = routes.size();
        Set.resize(size);
        for(int i = 0; i < size; i++) {
            for (int j = 0; j < routes[i].size(); j++) {
                Set[i].insert(routes[i][j]);//Set中存储了一辆车可以到达的站点信息
            }
        }
        vector<vector<int>> graph(size);//将size作为起点，size+1作为终点，这是车之间的graph
        //build the graph
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                if (check(i, j, routes)) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }                    
            }
        }
        queue<int> que;
        vector<int> visited(size, 0);
        int level = 1;
        for (int i = 0; i < size; i++) {
            if (Set[i].count(S)){//如果一辆车驶经S，说明它是起点可以到达的车
                que.push(i);//准备好作为起点的车
                if (Set[i].count(T))
                    return level;
            }
                
        }
        while (!que.empty()) {
            level++;
            for (int i = que.size(); i > 0; i--) {
                int cur = que.front();
                que.pop();
                for (auto& x : graph[cur]) {//将cur的后继加入que中。
                    if (visited[x] != 0) 
                        continue;
                    visited[x] = 1;
                    que.push(x);
                    if (Set[x].count(T))
                        return level;
                }
            }
        }
        return -1;
    }
};

class Solution1 {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if (S == T)
            return 0;
        unordered_map<int, vector<int>> stop2bus;
        for (int i = 0; i < routes.size(); i++) {
            for (const auto& stop : routes[i]) {
                stop2bus[stop].push_back(i);
            }
        }
        queue<int> q{{S}};
        int level = 0;
        unordered_set<int> visited;
        while (!q.empty()) {
            for (int k = q.size(); k > 0; k--) {
                auto curStop = q.front(); q.pop();
                if (curStop == T) {
                    return level;
                }
                for (const auto& bus : stop2bus[curStop]) {
                    if (visited.count(bus)) {
                        continue;
                    }
                    visited.insert(bus);
                    for (const auto& stop : routes[bus]) {
                        q.push(stop);
                    }
                }
            }
            level++;
        }

        return -1;
    }
};

class Solution2 {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if (S == T) return 0;
        int level = 0;
        unordered_map<int, vector<int>> stop2bus;
        queue<int> q{{S}};
        unordered_set<int> visited;
        for (int bus = 0; bus < routes.size(); ++bus) {
            for (int stop : routes[bus]) {
                stop2bus[stop].push_back(bus);
            }
        }
        while (!q.empty()) {
            ++level;
            for (int i = q.size(); i > 0; --i) {
                int t = q.front(); q.pop();
                for (int bus : stop2bus[t]) {
                    if (visited.count(bus)) continue;
                    visited.insert(bus);
                    for (int stop : routes[bus]) {
                        if (stop == T) return level;
                        q.push(stop);
                    }
                }
            }
        }
        return -1;
    }
};