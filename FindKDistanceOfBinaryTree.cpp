/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void treeToGraph(TreeNode* root, unordered_map<int, vector<int>>& graph) {
        if (!root) return;

        if (root->left) {
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
            treeToGraph(root->left, graph);
        }

        if (root->right) {
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
            treeToGraph(root->right, graph);
        }
    }

    void dfs(int currVertex, int parent, int k, unordered_map<int, vector<int>>& graph, vector<int>& result) {
        if (k == 0) {
            result.push_back(currVertex);
            return;
        }

        for (auto child : graph[currVertex]) {
            if (child == parent) continue;
            dfs(child, currVertex, k - 1, graph, result);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int, vector<int>> graph;
        treeToGraph(root, graph);

        vector<int> result;
        dfs(target->val, -1, k, graph, result);

        return result;
    }
};