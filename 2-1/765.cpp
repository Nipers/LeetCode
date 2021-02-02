#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
using namespace std;
//该算法相当于把一个连通分量拆成多个自连通分量，需要拆几次就需要交换几次。
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int size = row.size(), half = size >> 1, res = half;
        int couples[half][2] = {{0}};//couples里存储的是第几对夫妻分别所在的沙发号
        for (int i = 0; i < size; i++) 
            if (couples[row[i] >> 1][0]) 
                couples[row[i] >> 1][1] = (i >> 1) + 1;
            else 
                couples[row[i] >> 1][0] = (i >> 1) + 1;
        int adj[half + 1][2] = {{0}};//adj中存储的是那张指向图
        for (int i = 0; i < half; i++) {
            if (adj[couples[i][0]][0])
                adj[couples[i][0]][1] = couples[i][1];
            else 
                adj[couples[i][0]][0] = couples[i][1];
            if (adj[couples[i][1]][0])
                adj[couples[i][1]][1] = couples[i][0];
            else 
                adj[couples[i][1]][0] = couples[i][0];
        }
        for (int r = 1; r <= half; r++) {
            if (adj[r][0] == 0 && adj[r][1] == 0)//自连通分量
                continue;
            res--;//该节点不需要进行交换操作
            int x = r, y;
            if (adj[r][0] != 0) {
                y = adj[r][0];
                adj[r][0] = 0;
            }
            else {
                y = adj[r][1];
                adj[r][1] = 0;
            }
            while (y != r) {
                if (adj[y][0] == x)
                    adj[y][0] = 0;
                else
                    adj[y][1] = 0;
                x = y;
                if (adj[x][0] != 0) {
                    y = adj[x][0];
                    adj[x][0] = 0;
                }
                else {
                    y = adj[x][1];
                    adj[x][1] = 0;
                }
            }
        }
        return res;
    }
};