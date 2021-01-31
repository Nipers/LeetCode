
#include<vector>
#include<string>
#include<queue>
#include<unordered_set>
#include<unordered_map>
#include<math.h>
#include<string.h>
using namespace std;
class Solution {
public:
    void merge(int i, int j, vector<int>& unionset) {
        unionset[find(j, unionset)] = find(i, unionset);
    }
    int find(int i, vector<int>& unionset) {
        if (unionset[i] == i)
            return i;
        unionset[i] = find(unionset[i], unionset);
        return unionset[i];
    } 
    int largestComponentSize(vector<int>& A) {
        int size = A.size(), temp;
        vector<unordered_set<int>> prime(size);
        for (int i = 0; i < size; i++) {
            temp = A[i];
            for (int j = 2; j <= sqrt(temp); j++) {
                if (temp % j == 0) {
                    while (temp % j == 0) {
                        temp /= j;
                    }
                    prime[i].insert(j);
                }
            }                
            if (temp > 1 || prime[i].size() == 0) {
                prime[i].insert(temp);
            }
        }
        unordered_set<int> primes;
        for (int i = 0; i < size; i++) {
            for (int j : prime[i])
                primes.insert(j);
        }        
        unordered_map<int, int> prime_to_index;
        vector<int> index_to_prime(primes.size());
        int index = 0;
        for (int j : primes) {
            prime_to_index[j] = index;
            index_to_prime[index] = j;
            index++;
        }
        vector<int> unionset(primes.size());
        for (int i = 0; i < primes.size(); i++) 
            unionset[i] = i;
        for (int i = 0; i < size; i++) {
            int temp = prime_to_index[*prime[i].begin()];
            for (int x : prime[i])
                merge(temp, prime_to_index[x], unionset);//将所有质数对应下标进行并查集合并
        }
        vector<int> ans(primes.size(), 0);
        for (int i = 0; i < size; i++) {
            ans[find(prime_to_index[*prime[i].begin()], unionset)]++;
        }
        int res = 0;
        for (int i: ans)
            res = res > i ? res : i;
        return res;
    }
};
class Solution2 {
public:
    vector<int> unionset, siz;//
    int v[100005], ans;
    bool vis[100005];
    int Find(int x){
        return x == unionset[x] ? x: unionset[x] = Find(unionset[x]);
    }
    void Union(int x, int y){
        int fx = Find(x), fy = Find(y);
        if (fx == fy) return ;
        if (siz[fx] > siz[fy]){
            unionset[fy] = fx, siz[fx] += siz[fy], ans = max(ans, siz[fx]);
        }else {
            unionset[fx] = fy, siz[fy] += siz[fx], ans = max(ans, siz[fy]);
        }
    }
    int largestComponentSize(vector<int>& A) {
        int n = A.size(), maxi = -1;
        memset(v, -1, sizeof(v));
        memset(vis, 0, sizeof(vis));
        unionset = vector<int>(n, 0);
        siz = vector<int>(n, 1);
        ans = 0;
        for (int i = 0; i < n; ++i)
            unionset[i] = i, v[A[i]] = i, maxi = max(maxi, A[i]);
        for (int i = 2; i <= maxi; ++i){
            if (!vis[i]){
                int t = -1;
                if (v[i] >= 0) t = v[i];
                for (int j = i + i; j <= maxi; j += i){
                    if (v[j] >= 0) {
                        if (t < 0) t = v[j];
                        else Union(t, v[j]);
                    }
                    vis[j] = true;
                }
            }
        }
        return ans;
    }
};