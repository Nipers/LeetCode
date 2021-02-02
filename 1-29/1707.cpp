#include<unordered_map>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    struct item {
        int freq = 0;
        int next = -1;
    };

    unordered_map<string, int> s2i; // 字符串到索引的映射
    vector<string> i2s; // 索引到字符串的逆映射
    vector<item> ufs; // 并查集

    // 尝试建立新的名字、索引对，返回名字对应的索引
    int emplace(string name, int freq) {
        const auto [it, b] = s2i.emplace(name, s2i.size());
        if (b) {
            i2s.push_back(name);
            ufs.push_back({freq, -1});
        }
        return it->second;
    }

    int find(int x) {
        return ufs[x].next == -1 ? x : ufs[x].next = find(ufs[x].next);
    }

    bool merge(int a, int b) {
        int fa = find(a), fb = find(b);
        if (fa == fb) return false;
        if (i2s[fa] < i2s[fb])
            swap(fa, fb);
        ufs[fa].next = fb;
        ufs[fb].freq += ufs[fa].freq;
        ufs[fa].freq = 0;
        return true;
    }

    vector<string> trulyMostPopular(vector<string>& names, vector<string>& synonyms) {
        for (const auto& e : names) {
            string v = e; // 转化为视图
            const int l = v.rfind('('); // 左括号位置
            const int r = v.size() - 1; // 右括号位置
            const auto f = v.substr(l + 1, r - l - 1); // 频率
            emplace(v.substr(0, l), stoi(string(f)));
        }
        for (const auto& e : synonyms) {
            string v = e; // 转化为视图
            const int n = v.size(); // 字符串长度
            const int d = v.find(','); // 分隔符位置
            const auto s1 = v.substr(1, d - 1); // 第一个名字
            const auto s2 = v.substr(d + 1, n - d - 2); // 第二个名字
            merge(emplace(s1, 0), emplace(s2, 0));
        }
        vector<string> ret;
        const int n = ufs.size();
        for (int i = 0;i < n;++i) {
            if (ufs[i].freq != 0) {
                string s(i2s[i]);
                s += '(';
                s += to_string(ufs[i].freq);
                s += ')';
                ret.emplace_back(move(s));
            }
        }
        return ret;
    }
};