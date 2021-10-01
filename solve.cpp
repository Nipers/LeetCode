#include<vector>
#include<set>
#include<iostream>
using namespace std;

class transactions {
public:
    vector<vector<int>> front;
    vector<int> size;
    vector<int> fee;
    transactions() {
        front = vector<vector<int>>(13);
        // front[1].push_back();
        // front[2].push_back();
        front[3].push_back(1);
        front[4].push_back(1), front[4].push_back(2);
        // front[5].push_back();
        front[6].push_back(3);
        front[7].push_back(3);
        front[8].push_back(3);
        front[9].push_back(4), front[9].push_back(5);
        front[10].push_back(6), front[10].push_back(8);
        front[11].push_back(2), front[11].push_back(7);
        front[12].push_back(8), front[12].push_back(9);
        size = vector<int> (13);
        fee = vector<int> (13);
        size[1] = 1, size[2] = 2, size[3] = 1, size[4] = 4;
        size[5] = 3, size[6] = 2, size[7] = 3, size[8] = 3;
        size[9] = 3, size[10] = 1, size[11] = 2, size[12] = 1;
        fee[1] = 1, fee[2] = 1, fee[3] = 2, fee[4] = 3, fee[5] = 4;
        fee[6] = 2, fee[7] = 4, fee[8] = 2, fee[9] = 2, fee[10] = 2;
        fee[11] = 3, fee[12] = 4; 
    };

    set<int> getFront(set<int> input) {
        vector<int> in;
        set<int> out;
        for (int i : input) {
            in.push_back(i);
            out.insert(i);
        }
        int left = 0;
        while (left < in.size()) {
            int cur = in[left];
            for (int i : front[cur]) {
                if (out.find(i) == out.end()) {
                    out.insert(i);
                    in.push_back(i);
                }
            }
            left++;
        }
        return out;
    }
    pair<int, int> result(set<int> input) {
        int res = 0, siz = 0;
        for (int i : input) {
            res += fee[i];
            siz += size[i];
        }
        return {res, siz};
    }
};

set<int> decode (int input) {
    int one = 1;
    set<int> res;
    for (int i = 0; i < 12; i++) {
        if ((one << i) & input) {
            res.insert(i + 1);
            cout << i + 1;
        }
    }
    return res;
}
int main() {
    transactions ts;
    // int b = 18, fee = 0;
    // set<int> I;
    // for (int i = 1; i < 4096; i++) {
    //     set<int> temp = decode(i);
    //     pair<int, int> res = ts.result(ts.getFront(temp));
    //     if (res.second <= b) {
    //         if (fee < res.first) {
    //             fee = res.first;
    //             I = ts.getFront(temp);
    //         }
    //         if (fee == res.first) {
    //             cout << "-----------" << res.first << " " << res.second << "\n";
    //             for (int x : ts.getFront(temp)) {
    //                 cout << x << " ";
    //             }
    //             cout << "\n";
    //         }
    //     }
    // } 
    // for (int x : I) {
    //     cout << x << " ";
    // }
    // cout << "\n";
    set<int> temp;
    temp.insert(12);
    // temp.insert(10);
    // temp.insert(11);
    set<int> res = ts.getFront(temp);
    pair<int, int> r = ts.result(res);
    cout << r.first << " " << r.second;
    cout << "\n";
    return 0;
}