class MyQueue {
private:
    int * data;
    int left, right;
public:
    MyQueue(int size) {
        data = new int[size];
        left = 0;
        right = -1;
    }
    void insert(int num) {
        while (left <= right && data[right] < num) {
            right--;
        }
        data[++right] = num;
    }
    void leave(int num) {
        if (data[left] == num) {
            left++;
        }
    }
    int get() {
        return data[left];
    }
};