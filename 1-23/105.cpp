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

class Solution1 {
public:
    unordered_map<int, int> table;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++)
            table[inorder[i]] = i;            
        return build(preorder, 0, 0, inorder.size());
    }
    TreeNode* build(vector<int>& preorder, int pre, int in_, int len) {
        if (len == 0)
            return NULL;
        TreeNode * root = new TreeNode();
        root -> val = preorder[pre];
        int index = table[preorder[pre]];//根节点在中序遍历中的下标
        int len1 = index - in_;
        int len2 = len - len1 - 1;
        root -> left = build(preorder, pre + 1, in_, len1);
        root -> right = build(preorder, pre + len1 + 1, index + 1, len2);
        return root;
    }
};

class Solution2 {//思考一下怎么做下一题。
public:
    int pre = 0, i = 0, size;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {   
        size = preorder.size();  
        return build(preorder, inorder, INT_MAX);
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int stop) {
        if (pre == size)
            return NULL;
        if (inorder[i] == stop) {
            i++;
            return NULL;
        }
        int root_val = preorder[pre++];
        TreeNode* root = new TreeNode(root_val);
        root -> left = build(preorder, inorder, root_val);//将根节点作为终止条件 
        root -> right = build(preorder, inorder, stop);
        return root;
    }
};