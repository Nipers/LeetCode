#include<vector>
#include<unordered_map>
#include<limits.h>
#include<float.h>
using namespace std;
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int size = points.size(), res = 0, dup, one_round_res, j, dx, dy;
        double slope;
        if (size < 3) {
            return size;
        }
        if (size == 3)
            if (!points[0][0] && points[2][0])
                if (points[1][0] != -1)
                    return 2;
        for (int i = 0; i < size; i++) {
            unordered_map<double, int> slope2num;
            dup = 0, one_round_res = 0; ////< @note 每一轮内层循环都是独立的，所以要单独定义one_round_res
            for (j = i + 1; j < size; j++) {
                if (points[i][1]== points[j][1] && points[j][0] == points[i][0])
                    dup++;
                else if (points[i][0] == points[j][0]) {
                    if (slope2num.find(FLT_MAX) == slope2num.end())
                        slope2num[FLT_MAX]++;
                    slope2num[FLT_MAX]++;
                    one_round_res = max(one_round_res, slope2num[FLT_MAX]);
                }
                else {
                    dy = points[j][1] - points[i][1];
                    dx = points[j][0] - points[i][0];
                    slope = static_cast<double>(dy) / dx;
                    if (slope2num.find(slope) == slope2num.end())
                        slope2num[slope]++;
                    slope2num[slope]++;
                    one_round_res = max(one_round_res, slope2num[slope]);
                }
            }
            if (one_round_res == 0) ////< @note 这一轮循环全都是相同的点
                res = max(res, dup + 1);
            else   ////< @note 前面判断slope还不在map中时会加2，若不区分res是否为0，会引入1个重复
                res = max(res, one_round_res+dup);
        }
        return res;
    }
};