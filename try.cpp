#include<iostream>

int main() {
    int x = 11;
    std::cout << ((x >> 1) + (x & 1)) << std::endl;
    return 0;
}