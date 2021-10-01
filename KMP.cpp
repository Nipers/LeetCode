#include <string>
#include <vector>
#include <iostream>
using namespace std;
vector<int> getNext(string pattern) {
	vector<int> next(pattern.size());
	next[0] = -1;
	int i  = 0, copyed = -1;
	while (i < (int)pattern.size() - 1) {
		if (copyed < 0 || pattern[copyed] == pattern[i] ){
			i++, copyed++;
			next[i] = copyed;
		}
		else {
			copyed = next[copyed];
		}
	}
	return next;
}
int KMP(string source, string pattern){
	vector<int> next = getNext(pattern);
	int i = 0, j = 0;
	while (i < (int)source.size() && j < (int)pattern.size()){//注意返回的是size_t，所以需要转化成int才能用
		if (j < 0 || pattern[j] == source[i]) {
			i++, j++;
		}
		else {
			j = next[j];
		}
	} 
	if (j == pattern.size()) {
		return i - j;
	}
	return -1;
}
int main() {
    cout << KMP("aaaABCDABD","ABCDABD");
    return 0;
}