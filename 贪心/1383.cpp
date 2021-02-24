#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
/* 
公司有编号为 1 到 n 的 n 个工程师，给你两个数组 speed 和 efficiency ，
其中 speed[i] 和 efficiency[i] 分别代表第 i 位工程师的速度和效率。请你
返回由最多 k 个工程师组成的 ​​​​​​最大团队表现值 ，由于答案可能很大，请你返回结果对
 10^9 + 7 取余后的结果。
团队表现值的定义为：一个团队中「所有工程师速度的和」乘以他们「效率值中的最小值」。
我的想法：将效率从小到大进行排序，每次固定效率最小的人，从效率比他大的人中选出k - 1位速度最大的。
遇到的问题：我不知道该怎么从n个人中选出速度最大的k - 1个，如果每次从堆中pop，时间复杂度为nklogn
题解：将效率从大到小进行排列，先将效率最高的k - 1个人的速度入堆，算出堆的元素和，
依次遍历效率更低的人，将其速度入堆，堆的最小元素出堆，维护元素和
思路差距在哪？n中选k个，不如先选好k个然后依次淘汰最小的那个*/
class Solution {
public:
    static bool compare(pair<int, int> a, pair<int, int> b) {
        return a.first > b.first;
    }
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        long long result = 0, sum = 0, temp;
        vector<pair<int, int>> eng(n);
        for (int i = 0; i < n; i++) {
            eng[i].first = efficiency[i];
            eng[i].second = speed[i];
        }
        sort(eng.begin(), eng.end(), compare);
        priority_queue<int, vector<int>, greater<int>> que;
        for (int i = 0; i < k - 1; i++) {
            que.push(eng[i].second);
            sum += eng[i].second;
            temp = sum * eng[i].first;
            result = temp > result ? temp : result;
        }
        for (int i = k - 1; i < n; i++) {
            temp = (sum + eng[i].second) * eng[i].first;
            result = temp > result ? temp : result;
            sum += eng[i].second;
            que.push(eng[i].second);
            sum -= que.top();
            que.pop();
        }
        return result % (int(1E9) + 7);
    }
};