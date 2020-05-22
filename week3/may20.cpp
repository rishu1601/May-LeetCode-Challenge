class Solution {
private:
    int res = -1, currInd = 0;
    void dfs(TreeNode *node, int k) {
        if(node == NULL)return;
        dfs(node->left, k);
        currInd += 1;
        if(currInd == k)
            res = node->val;
        else
            dfs(node->right, k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return res;
    }
};
