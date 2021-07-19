class unionSet{
private:
    int* s;
public:
    unionSet(int size) {
        s = new int[size];
        for (int i = 0; i < size; i++) {
            s[i] = i;
        }
    }
    int find(int x) {
        return x == s[x] ? x : s[x] = find(s[x]);
    }
    void merge(int x, int y) {
        s[find(x)] = find(y);
    }
};
class unionSet{
    private:
        int* s;
        int* num;
        int size;
    public:
    unionSet(int size) {
        this->size = size;
        s = new int[size];
        num = new int[size];
        for (int i = 0; i < size; i++) {
            s[i] = i;
            num[i] = 1;
        }
    }
    int find(int x) {
        return x == s[x] ? x : s[x] = find(s[x]);
    }
    void merge(int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx != fy) {
            if (num[fx] > num[fy]) {
                num[fx] += num[fy];
                s[fy] = fx;
            }
            else {
                num[fy] += num[fx];
                s[fx] = fy;
            }
        }
    }
    int getMax() {
        int max = 0;
        for (int i = 0; i < this->size; i++) {
            if (num[i] > max) {
                max = num[i];
            }
        }
        return max;
    }
};