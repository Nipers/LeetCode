#include<iostream>
#include<unordered_set>
#include<vector>
#include<string>
using namespace std;
int main() {
    for (int x = 0; x < 10; x++) {
        int num = 0;
        double sum = 0;
        int a[10];
        double b[10];
        for (int i = 0; i < 10; i++) {
            cin >> a[i];
            if (a[i] == 1)
                num++;
        }
        b[0] = a[0];
        for (int i = 1; i < 10; i++) {
            b[i] = b[i - 1] + a[i];
        }
        for (int i = 1; i < 10; i++) {
            b[i] /= (i + 1);
        }
        for (int i = 0; i < 10; i++) {
            if (a[i] == 1) {
                sum += b[i];
            }
        }
        cout << (sum / num);
    }
    return 0;
}