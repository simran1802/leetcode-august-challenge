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
public:
    int pathSum(TreeNode* root, int sum) {
        unordered_map <int,int> map;
        return dfs(root,0,sum,map);
    }
    
        int dfs(TreeNode *node, int root_to_parent, int s, unordered_map<int, int> &map) {        
            if(!node)
            return 0;
        int root_to_node = root_to_parent + node->val;
        
        int paths = map[root_to_node -s] + (root_to_node == s?1:0);
        map[root_to_node] += 1;
        
        int left = dfs(node->left,root_to_node,s,map);
        int right = dfs(node->right,root_to_node,s,map);
        
        map[root_to_node] -= 1;
        return paths + left + right;
    }
};
