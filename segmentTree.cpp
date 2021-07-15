class segmentTree {
private:
    int *tree;
    int *mark;
public:
    segmentTree(int size, int * ans) {
        tree = new int[2 * size];
        mark = new int[2 * size];
        build(0, size - 1, 0, ans);
    }
    ~segmentTree() {
        delete tree;
        delete mark;
    }
    void build(int l, int r, int index, int* ans) {
        if (l == r) {
            tree[index] = ans[l];
            return;
        }
        int mid = (l+r)>>1;
        build(l, mid, 2 * index, ans);
        build(mid + 1, r, 2 * index + 1, ans);
        tree[index] = tree[index * 2] + tree[2 * index + 1];
    }
    int getSum(int l, int r, int s, int t, int index) {
        if (s <= l && t >= r) {
            return tree[index]; 
        }
        if (l == r)
            return 0;
        int mid = (l + r) >> 1;
        if (mark[index]) {
            tree[2 * index] += (mid - l + 1) * mark[index];
            tree[2 * index + 1] += (r - mid) * mark[index];
            mark[2 * index] += mark[2 * index + 1] += mark[index];
            mark[index] = 0;            
        }
        return getSum(l, mid, s, t, index << 1) + getSum(mid + 1, r, s, t, (index << 1) + 1);
    }
    void update(int l, int r, int c, int s, int t, int index) {//该版本是将从s到t的结果加上
        if (s <= l && t >= r) {
            tree[index] += (r - l + 1) * c;
            mark[index] = c;
            return;
        }
        if (l == r)
            return;
        int mid = (l + r) >> 1;
        if (mark[index] != 0) {
            tree[2 * index] += (mid - l + 1) * mark[index];
            tree[2 * index + 1] += (r - mid) * mark[index];
            mark[2 * index] += mark[2 * index + 1] += mark[index];
            mark[index] = 0;
        }
        update(l, mid, c, s, t, 2 * index);
        update(mid + 1, r, c, s, t, 2 * index + 1);
        tree[index] = tree[index * 2] + tree[2 * index + 1];
    }
};