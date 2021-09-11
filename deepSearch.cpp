#include<stack>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = root->val;
        stack<TreeNode*> s;
        s.push(root);
        while(s.size() > 0) {
            while(s.top()->left != nullptr || s.top()->right!=nullptr) {
                if (s.top()->left != nullptr) {
                    sum += s.top()->left->val;
                    s.push(s.top()->left);
                }
                else {
                    sum += s.top()->right->val;
                    s.push(s.top()->right);
                }
            }
            if (sum == targetSum) 
                return true;
            while(true) {
                TreeNode* child = s.top();
                sum -= child->val;
                s.pop();
                if (s.top() ->right != nullptr) {
                    s.push(s.top() ->right);
                    break;
                }
            }
        }
        return false;
    }
};