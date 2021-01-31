#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;
//带权并查集：实现要点在于，在find时
class Solution {
public:
    vector<double> value;//记录变量值
    vector<int> unionset;
    unordered_map<string, int> var_to_index;
    void merge(int i, int j, vector<int>& unionset, double time) {
        int fi = find(i, unionset), fj = find(j, unionset);
        unionset[fi] = fj;
        value[fi] = time * value[j] / value[i];//根节点值需要扩大的倍数，因为根节点是没有经过赋值的点，所以不需要进行乘法
    }
    int find(int i, vector<int>& unionset) {
        if (unionset[i] != i) {
            int father = find(unionset[i], unionset);
            value[i] *= value[unionset[i]];//不会有两层以上的树，所以直接乘以之前父节点的值即可。
            unionset[i] = father;
        }
        return unionset[i];
    } 
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int size = equations.size(), index = 0;
        for (int i = 0; i < size; i++) {
            if (var_to_index.find(equations[i][0]) == var_to_index.end())
                var_to_index[equations[i][0]] = index++;
            if (var_to_index.find(equations[i][1]) == var_to_index.end())
                var_to_index[equations[i][1]] = index++;
        }
        size = index;
        value = vector<double>(size, 1.0);
        unionset = vector<int>(size);
        index = 0;
        for (index; index < size; index++) {
            unionset[index] = index;
        }
        for (int i = 0; i < equations.size(); i++) {
            int m = var_to_index[equations[i][0]], n = var_to_index[equations[i][1]];
            merge(m, n, unionset, values[i]);
        }
        vector<double> ans;
        for (int i = 0; i < queries.size(); i++) {
            double result = -1.0;
            if (var_to_index.find(queries[i][0]) != var_to_index.end() && var_to_index.find(queries[i][1]) != var_to_index.end()) {
                int m = var_to_index[queries[i][0]], n = var_to_index[queries[i][1]];
                if (find(m, unionset) == find(n, unionset)) {
                    result = value[m] / value[n];
                }
            }
            ans.push_back(result);
        }
        return ans;
    }
};