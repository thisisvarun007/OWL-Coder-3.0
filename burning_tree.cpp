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
    unordered_map<int,int> visit;
    unordered_map<int,vector<int>> adj;
    void traverse(TreeNode *rt){
        if (!rt)return;
        if (rt->left){
            adj[rt->val].push_back(rt->left->val);
            adj[rt->left->val].push_back(rt->val);
        }
        if (rt->right){
            adj[rt->val].push_back(rt->right->val);
            adj[rt->right->val].push_back(rt->val);
        }
        traverse(rt->left);
        traverse(rt->right);
    }
    int amountOfTime(TreeNode* root, int start) {
        traverse(root);
        queue<int> q;
        q.push(start);
        visit[start] = 1;
        int time = -1;
        while (!q.empty()){
            int n = q.size();
            while (n--){
                int val = q.front();
                for (auto it : adj[val]){
                    if (visit[it] != 1){
                        q.push(it);
                        visit[it] = 1;
                    }
                }
                q.pop();
            }
            time++;
        }
        return time;
    }
};