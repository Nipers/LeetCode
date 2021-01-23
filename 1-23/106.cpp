#include<unordered_map>
#include<vector>
#include<limits.h>
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
    public:
    int post, i;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {   
        post = i = postorder.size() - 1;  
        return build(inorder, postorder, INT_MAX);
    }
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int stop) {
        if (post == -1)
            return NULL;
        if (inorder[i] == stop) {
            i--;
            return NULL;
        }
        int root_val = postorder[post--];
        TreeNode* root = new TreeNode(root_val);
        root -> right = build(inorder, postorder, root_val);
        root -> left = build(inorder, postorder, stop);//将根节点作为终止条件 
        return root;
    }
};