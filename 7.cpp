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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root==nullptr){
            return {};
        }
        
    map<int,vector<int>> m;
        vector<vector<int>> v;
        
        queue<pair<TreeNode*,int>>q;
        q.push({root,1});
        
        while(!q.empty()){
            int k=q.size();
            map<int,set<int>> m1;
            
        while(k--){
            TreeNode *cur = q.front().first;
            int h = q.front().second;
            q.pop();
            m1[h].insert(cur->val);
            if(cur->left){
                q.push({cur->left,h-1});
            }
            if(cur->right){
                q.push({cur->right,h+1});
            }
        }
        for(auto x:m1){
            for(auto d:x.second){
                m[x.first].push_back(d);
            }
        }
            
        }
        for(auto x:m)
    {
        //sort(x.second.begin(),x.second.end());
        v.push_back(x.second);
    }
    return v;
    }
};
