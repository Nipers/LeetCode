#include <vector>
using namespace std;
//栈式结构实现的中序遍历，精髓是栈顶的节点就是下一个目标节点。
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> stak;
        while (!stak.empty() || root != NULL) {
            while (root != NULL) {
                stak.push(root);
                root = root -> left;
            }
            root = stak.top();
            stak.pop();
            result.push_back(root -> val);
            root = root -> right;
        }
        return result;
    }
};