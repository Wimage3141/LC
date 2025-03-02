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
    void populateHeap(TreeNode* root, priority_queue<int, vector<int>, greater<int>>& minHeap) {
        if(!root) return;
        minHeap.push(root->val);
        populateHeap(root->left, minHeap);
        populateHeap(root->right, minHeap);
    }
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        populateHeap(root, minHeap);
        while(--k) {
            minHeap.pop();
        }

        return minHeap.top();
    }
};
