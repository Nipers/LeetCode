#include <string>
#include <vector>
using namespace std;

int manacheer(string input) {
    int size = input.size() * 2 + 1;
    vector<int> ans(size, 1);//至少自己是回文的
    char* in = new char[size];
    for (int i = 0; i < size; i += 2) {//预处理
        in[i] = '#';
    }
    for (int i = 1; i < size; i += 2) {
        in[i] = input[i >> 1];
    }
    int c = 0, r = 0;
    for (int i = 1; i < size; i++) {
        int temp = 0;
        if (i < r) {
            int mirror = 2 * c - i;
            temp = ans[mirror] > r - i ? r - i : ans[mirror];
        }
        int left = i - temp - 1, right = i + temp + 1;
        while (left >= 0 && right < size) {
            if (in[left] == in[right]) {
                temp++;
                left--, right++;
            }
            else
                break;
        }
        if (i + temp > r) {
            r = i + temp;
            c = i;
        }
        ans[i] = temp;
    }

}