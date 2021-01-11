#include<iostream>

int x[10];
int main() {
    for (int i = 0; i < 10; i++) {
        x[i] = 1 << i;
    }
    return 0;
}