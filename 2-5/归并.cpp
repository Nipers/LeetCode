#include<vector>
using namespace std;
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int size = nums.size();
        if (size == 1)
            return nums;
        int *A = new int[size], *B = new int[size], *temp;
        for (int i = 0; i < size; i++)
            A[i] = nums[i];
        int len1 = 2, len2 = 1, time = 0, num, a, b, c, alpha, beta;
        while (size > len2) {
            if (time != 0) {
                temp = A;
                A = B;
                B = temp;
            }
            c = 0;
            while (c <= size - len1) {
                a = c, b = alpha = len2 + c, beta = len1 + c;
                while(c < beta) {
                    if (a < alpha && b < beta) {
                        if (A[a] < A[b]) 
                            B[c++] = A[a++];
                        else 
                            B[c++] = A[b++];
                    }
                    else if (a < alpha)
                        B[c++] = A[a++]; 
                    else
                        B[c++] = A[b++];
                }
            }
            if (size % len1) {
                c = size - (size % len1);
                if (size % len1 <= len2) {
                    while (c < size) {
                        B[c] = A[c];
                        c++;
                    }
                }
                else {
                    a = c, b = alpha = a + len2, beta = size;
                    while(c < beta) {
                        if (a < alpha && b < beta) {
                            if (A[a] < A[b]) 
                                B[c++] = A[a++];
                            else 
                                B[c++] = A[b++];
                        }
                        else if (a < alpha)
                            B[c++] = A[a++]; 
                        else
                            B[c++] = A[b++];
                    }
                }
            }
            time++;
            len2 = len1, len1 <<= 1;
        }
        for (int i = 0; i < size; i++)
            nums[i] = B[i];
        return nums;
    }
};