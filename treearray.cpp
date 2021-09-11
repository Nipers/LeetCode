class BinaryIndexedTree {
private:
    int* bitArr;
    int len;
public:
    BinaryIndexedTree(int* list, int length) {
        len = length + 1;
		bitArr = new int[length + 1];//第一步，按原数组赋值
		for (int i = 0; i < length; i++) {
			bitArr[i + 1] = list[i];
		}
		
		for (int i = 1; i < length; i++) {//第二步，每个节点将自己的值加到父亲那去，父亲的下标idx+（idx&-idx）
			int j = i + (i & -i);
			if (j < len) {
				bitArr[j] += bitArr[i];
			}
		}
	}
	void update(int idx, int delta) {
		idx += 1;
		while (idx < len) {//update操作：从自己一直到父亲，到祖父一直加下去。父亲变为idx+(idx&-idx)，注意这里是增量更新。
			bitArr[idx] += delta;
			idx = idx + (idx & -idx);
		}
	}
	int prefixSum(int idx) {//前缀和求法：从父亲求起，一直求到最小的孩子，父亲到孩子的公式：idx-(idx&-idx)
		idx += 1;
		int result = 0;
		while (idx > 0) {
			result += bitArr[idx];
			idx = idx - (idx & -idx);
		}		
		return result;
	}
	int rangeSum(int from_idx, int to_idx) {
		return prefixSum(to_idx) - prefixSum(from_idx - 1);
	}
};