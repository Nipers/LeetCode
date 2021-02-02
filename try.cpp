#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
using namespace std;
int main() {
    int a[5][2];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 2; j++) 
            cout << a[i][j] + i << endl;
    }
    return 0; 
}