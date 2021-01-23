#include <string>
#include <unordered_map>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    unordered_map<TreeNode*, int> Max;//用于存储必含某一节点的最大路径和
    int res = -2147483648;
    void setMax(TreeNode* root) {//在这之前需要更新Max值。
        int x = root -> val;
        int temp;
        if (root -> left != NULL) {
            temp = Max[root -> left];
            if (temp > 0)
                x += temp;
            setMax(root -> left);
        }
        if (root -> right != NULL) {
            temp = Max[root -> right];
            if (temp > 0)
                x += temp;
            setMax(root -> right);
        }
        res = max(res, x);
    }    
    int update(TreeNode* root) {
        Max[root] = root -> val;
        int temp = 0;
        if (root -> left != NULL)
            temp = max(temp, update(root -> left));
        if (root -> right != NULL)
            temp = max(temp, update(root -> right));
        Max[root] += temp;
        return Max[root];        
    }
    int maxPathSum(TreeNode* root) {
        update(root);
        setMax(root);
        return res;
    }
};

class Solution {
    int maxSum = -2147483648;
public:
    int maxGain(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        // 递归计算左右子节点的最大贡献值
        // 只有在最大贡献值大于 0 时，才会选取对应子节点
        int leftGain = max(maxGain(node->left), 0);
        int rightGain = max(maxGain(node->right), 0);
        // 节点的最大路径和取决于该节点的值与该节点的左右子节点的最大贡献值
        int priceNewpath = node->val + max(maxGain(node->left), 0) + max(maxGain(node->right), 0);
        // 更新答案
        maxSum = max(maxSum, priceNewpath);
        // 返回节点的最大贡献值
        return node->val + max(leftGain, rightGain);
    }

    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return maxSum;
    }
};
class Solution {
public:
    int ans = -2147483648;
    int find(TreeNode* root) {
        if (!root) return 0;
        int l = find(root->left), r = find(root->right);
        ans = max(ans, root->val + max(0, l) + max(0, r));
        return root->val + max(max(l, r), 0);
    }

    int maxPathSum(TreeNode* root) {
        ans = max(ans, find(root));
        return ans;
    }
};