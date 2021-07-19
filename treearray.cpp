class BinaryIndexedTree {
private:
    int* bitArr;
    int len;
public:
    BinaryIndexedTree(int* list, int length) {
        len = length + 1;
		bitArr = new int[length + 1];
		for (int i = 0; i < length; i++) {
			bitArr[i + 1] = list[i];
		}
		
		for (int i = 1; i < length; i++) {
			int j = i + (i & -i);
			if (j < len) {
				bitArr[j] += bitArr[i];
			}
		}
	}
	void update(int idx, int delta) {
		idx += 1;
		while (idx < len) {
			bitArr[idx] += delta;
			idx = idx + (idx & -idx);
		}
	}
	int prefixSum(int idx) {
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