/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    struct nodeInfo{
        int parent;
        TreeNode* currNode;
        int level;
        
        nodeInfo(int p, TreeNode* t, int l){
            parent = p;
            currNode = t;
            level = l;
        }
    };
public:
    bool isCousins(TreeNode* root, int x, int y) {
      if(root == NULL)return true;
        queue<nodeInfo> q;
        nodeInfo n1(0,NULL,0);
        nodeInfo n2(0,NULL,0);
        q.push(nodeInfo(-1, root, 0));
        int level = 0;
        while(!q.empty()) {
            int s = q.size();
            level += 1;
            while(s--){
                nodeInfo fr = q.front();
                q.pop();
                TreeNode* curr = fr.currNode;
                if(curr->val == x){
                    n1.parent = fr.parent;
                    n1.level = fr.level;
                    n1.currNode = curr;
                }
                if(curr->val == y){
                    n2.parent = fr.parent;
                    n2.level = fr.level;
                    n2.currNode = curr;
                }
                if(curr->left != NULL) {
                    q.push(nodeInfo(curr->val, curr->left, level));
                }
                if(curr->right != NULL) {
                    q.push(nodeInfo(curr->val, curr->right, level));
                }
            }
        }
        return (n1.level == n2.level && n1.parent != n2.parent);
    }
};
