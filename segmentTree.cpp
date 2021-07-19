#include<vector>
#include<iostream>
#include<unordered_map>
#include<set>
using namespace std;

struct Node {//[l,r)
    int l;
    int r;
    int height;
    Node() : l(0), r(0), height(0) {}
};

class Tree {
private:
    Node* nodes;
    int s;
public:
    vector<vector<int>> ans;
    vector<int> temp;
    Tree(int size) {
        s = size;
        temp.resize(2);
        nodes = new Node[4 * size];
        nodes[1].l = 0;
        nodes[1].r = size - 1;
        int father, left, right, mid;
        for (int i = 2; i < 4 * size - 1; i += 2) {
            father = (i >> 1);
            left = nodes[father].l, right = nodes[father].r;
            if (left < right - 1) {
                mid = (left + right) >> 1;
                nodes[i].l = left;
                nodes[i].r = mid;
                nodes[i + 1].l = mid;
                nodes[i + 1].r = right;
            }
        } 
    }
    ~Tree() {
        delete[] nodes;
    }
    void print() {               
        for (int i = 1; i < 4 * s; i++) {
            if (nodes[i].l == nodes[i].r - 1)
                cout << nodes[i].l << "  " << nodes[i].r << " " << nodes[i].height <<  endl;
        }
    }
    void update(int l, int r, int height, int index) {
        if (nodes[index].l >= r || nodes[index].r <= l)
            return;
        if (nodes[index].l >= l && nodes[index].r <= r) {
            nodes[index].height = nodes[index].height > height ? nodes[index].height : height;
            return;
        }
        if (nodes[index].l == nodes[index].r - 1)
            return;
        if (nodes[index].height != 0) {
            nodes[index << 1].height = nodes[index << 1].height > nodes[index].height ? nodes[index << 1].height : nodes[index].height;
            nodes[(index << 1) + 1].height = nodes[(index << 1) + 1].height > nodes[index].height ? nodes[(index << 1) + 1].height : nodes[index].height;
            nodes[index].height = 0;
        }
        update(l, r, height, index << 1);
        update(l, r, height, (index << 1) + 1);
    }
    void clear() {
        for (int index = 1; index < 4 * s; index++) {
            if (nodes[index].l < nodes[index].r - 1 && nodes[index].height) {
                nodes[index << 1].height = nodes[index << 1].height > nodes[index].height ? nodes[index << 1].height : nodes[index].height;
                nodes[(index << 1) + 1].height = nodes[(index << 1) + 1].height > nodes[index].height ? nodes[(index << 1) + 1].height : nodes[index].height;
                nodes[index].height = 0;
            }
        }
    } 
    vector<vector<int>> getAns() {
        sum(1);
        return ans;
    }
    void sum(int index) {
        if (nodes[index].l == nodes[index].r - 1) {
            if(ans[ans.size() - 1][1] != nodes[index].height) {
                temp[0] = nodes[index].l;
                temp[1] = nodes[index].height;
                ans.push_back(temp);
            }
        }
        else {
            sum(2*index);
            sum(2*index + 1);
        }
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
        Tree tree(num);
        for (auto x : buildings) {
            tree.update(locToIndex[x[0]], locToIndex[x[1]], x[2], 1);
        }
        tree.clear();
        tree.print();
        vector<vector<int>> ans = tree.getAns();
        // for (int i = 0; i < ans.size() ;i++) {
        //     ans[i][0] = indexToLoc[ans[i][0]];
        // }
        return ans;
    }
};


//注意在修改过程中学会根据修改的形式进行随机应变，如，如果只进行单个元素的修改，b数组根本就没有什么用处。
//本实现中以1为根节点，从始至终为闭集进行操作。p为当前节点下标，s，t在建树时为原数组，在查询和更新时为树的节点。
//当心更新值为0的问题。
class segmentTree
{
private:
    int* d;
    int* b;
public:
    segmentTree(vector<int> a) {
        d = new int[4 * a.size()];
        b = new int[4 * a.size()];
        for (int i = 0; i < 4 * a.size(); i++) {
            b[i] = 0;
        }
        build(0, a.size() - 1, 1, a);
    }
    void build(int s, int t, int p, vector<int> a) {
        // 对 [s,t] 区间建立线段树,当前根的编号为 p
        if (s == t) {
            d[p] = a[s];
            return;
        }
        int m = s + ((t - s) >> 1);
        // 移位运算符的优先级小于加减法，所以加上括号
        // 如果写成 (s + t) >> 1 可能会时间超限
        build(s, m, p * 2, a), build(m + 1, t, p * 2 + 1, a);
        // 递归对左右区间建树
        d[p] = d[p * 2] + d[(p * 2) + 1];
    }
    // void update(int l, int r, int c, int s, int t, int p) {
    //     // [l,r] 为修改区间,c 为被修改的元素的变化量,[s,t] 为当前节点包含的区间,p
    //     // 为当前节点的编号
    //     if (l <= s && t <= r) {
    //         d[p] += (t - s + 1) * c, b[p] += c;
    //         return;
    //     }  // 当前区间为修改区间的子集时直接修改当前节点的值,然后打标记,结束修改
    //     int m = s + ((t - s) >> 1);
    //     if (b[p] && s != t) {
    //         // 如果当前节点的懒标记非空,则更新当前节点两个子节点的值和懒标记值
    //         d[p * 2] += b[p] * (m - s + 1), d[p * 2 + 1] += b[p] * (t - m);
    //         b[p * 2] += b[p], b[p * 2 + 1] += b[p];  // 将标记下传给子节点
    //         b[p] = 0;                                // 清空当前节点的标记
    //     }
    //     if (l <= m) update(l, r, c, s, m, p * 2);
    //     if (r > m) update(l, r, c, m + 1, t, p * 2 + 1);
    //     d[p] = d[p * 2] + d[p * 2 + 1];
    // }
    // int getsum(int l, int r, int s, int t, int p) {
    //     // [l,r] 为查询区间,[s,t] 为当前节点包含的区间,p为当前节点的编号
    //     if (l <= s && t <= r) return d[p];
    //     // 当前区间为询问区间的子集时直接返回当前区间的和
    //     int m = s + ((t - s) >> 1);
    //     if (b[p]) {
    //         // 如果当前节点的懒标记非空,则更新当前节点两个子节点的值和懒标记值
    //         d[p * 2] += b[p] * (m - s + 1), d[p * 2 + 1] += b[p] * (t - m),
    //             b[p * 2] += b[p], b[p * 2 + 1] += b[p];  // 将标记下传给子节点
    //         b[p] = 0;                                    // 清空当前节点的标记
    //     }
    //     int sum = 0;
    //     if (l <= m) sum = getsum(l, r, s, m, p * 2);
    //     if (r > m) sum += getsum(l, r, m + 1, t, p * 2 + 1);
    //     return sum;
    // }
    void update(int l, int r, int c, int s, int t, int p) {
        if (l <= s && t <= r) {
            d[p] = (t - s + 1) * c, b[p] = c;
            return;
        }
        int m = s + ((t - s) >> 1);
        if (b[p]) {
            d[p * 2] = b[p] * (m - s + 1), d[p * 2 + 1] = b[p] * (t - m),
                b[p * 2] = b[p * 2 + 1] = b[p];
            b[p] = 0;
        }
        if (l <= m) update(l, r, c, s, m, p * 2);
        if (r > m) update(l, r, c, m + 1, t, p * 2 + 1);
        d[p] = d[p * 2] + d[p * 2 + 1];
    }
    int getsum(int l, int r, int s, int t, int p) {
        if (l <= s && t <= r) return d[p];
        int m = s + ((t - s) >> 1);
        if (b[p]) {
            d[p * 2] = b[p] * (m - s + 1), d[p * 2 + 1] = b[p] * (t - m),
                b[p * 2] = b[p * 2 + 1] = b[p];
            b[p] = 0;
        }
        int sum = 0;
        if (l <= m) sum = getsum(l, r, s, m, p * 2);
        if (r > m) sum += getsum(l, r, m + 1, t, p * 2 + 1);
        return sum;
    }
};

