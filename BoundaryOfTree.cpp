#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

// Helper function to create a tree from level-order traversal
TreeNode* createTreeLevelOrder(const vector<int>& levelOrderTree) {
    if (levelOrderTree.empty() || levelOrderTree[0] == -1) return nullptr;

    queue<TreeNode*> q;
    TreeNode* root = new TreeNode(levelOrderTree[0]);
    q.push(root);
    int index = 1;

    while (!q.empty() && index < levelOrderTree.size()) {
        TreeNode* currNode = q.front();
        q.pop();

        if (index < levelOrderTree.size() && levelOrderTree[index] != -1) {
            currNode->left = new TreeNode(levelOrderTree[index]);
            q.push(currNode->left);
        }
        index++;

        if (index < levelOrderTree.size() && levelOrderTree[index] != -1) {
            currNode->right = new TreeNode(levelOrderTree[index]);
            q.push(currNode->right);
        }
        index++;
    }
    return root;
}

// BFS to get all levels of the tree
vector<vector<int>> bfs(TreeNode* root) {
	if(!root) return {};
	queue<TreeNode*> q;
	q.push(root);
	vector<vector<int>> tree;
	while(!q.empty()) {
		int n = q.size();
		vector<int> level;
		for(int i = 0; i < n; i++) {
			TreeNode* currNode = q.front();
			q.pop();
			level.push_back(currNode->val);
			if(currNode->left) q.push(currNode->left);
			if(currNode->right) q.push(currNode->right);
		}
		tree.push_back(level);
	}
	return tree;
}


// Function to get the boundary of the binary tree using BFS
vector<int> boundaryOfBinaryTree(TreeNode* root) {
    if (!root) return {};

    vector<vector<int>> tree = bfs(root);
    vector<int> result;

    // Add the root (left boundary starts with root)
    result.push_back(tree[0][0]);

    // Add the left boundary (excluding leaves)
    for (int i = 1; i < tree.size() - 1; i++) {
        if (!tree[i].empty()) {
            result.push_back(tree[i][0]);
        }
    }

    // Add the leaves (last level)
    for (int val : tree.back()) {
        result.push_back(val);
    }

    // Add the right boundary (excluding leaves and root)
    for (int i = tree.size() - 2; i >= 1; i--) {
        if (tree[i].size() > 1) {
            result.push_back(tree[i].back());
        }
    }

    return result;
}

int main() {
    vector<int> levelOrderTree = {1, 2, 3, -1, 4, 5, 6};
    TreeNode* root = createTreeLevelOrder(levelOrderTree);

    vector<int> result = boundaryOfBinaryTree(root);
    cout << "Boundary: ";
    for (int i : result) cout << i << " ";
    cout << endl;

    return 0;
}


// #include <iostream>
// #include <vector>
// #include <queue>
// #include <climits>
// using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
// };

// void printBTLevelWise(TreeNode* root) {
//     if (!root) return;

//     queue<TreeNode*> q;
//     q.push(root);
//     while (!q.empty()) {
//         int levelSize = q.size();
//         for (int i = 0; i < levelSize; i++) {
//             TreeNode* currNode = q.front();
//             q.pop();
//             cout << currNode->val << " ";
//             if (currNode->left) q.push(currNode->left);
//             if (currNode->right) q.push(currNode->right);
//         }
//         cout << endl;
//     }
// }

// // Helper function to create a tree from level-order traversal
// TreeNode* createTreeLevelOrder(const vector<int>& levelOrderTree) {
//     if (levelOrderTree.empty() || levelOrderTree[0] == -1) return nullptr;

//     queue<TreeNode*> q;
//     TreeNode* root = new TreeNode(levelOrderTree[0]);
//     q.push(root);
//     int index = 1;

//     while (!q.empty() && index < levelOrderTree.size()) {
//         TreeNode* currNode = q.front();
//         q.pop();

//         if (index < levelOrderTree.size() && levelOrderTree[index] != -1) {
//             currNode->left = new TreeNode(levelOrderTree[index]);
//             q.push(currNode->left);
//         }
//         index++;

//         if (index < levelOrderTree.size() && levelOrderTree[index] != -1) {
//             currNode->right = new TreeNode(levelOrderTree[index]);
//             q.push(currNode->right);
//         }
//         index++;
//     }
//     return root;
// }

// // Helper function to get the left boundary (excluding leaves)
// void getLeftBoundary(TreeNode* root, vector<int>& result) {
//     if (!root || (!root->left && !root->right)) return; // Skip leaves

//     result.push_back(root->val);
//     if (root->left) getLeftBoundary(root->left, result);
//     else if (root->right) getLeftBoundary(root->right, result);
// }

// // Helper function to get the leaves (in-order)
// void getLeaves(TreeNode* root, vector<int>& result) {
//     if (!root) return;

//     if (!root->left && !root->right) {
//         result.push_back(root->val);
//         return;
//     }
//     getLeaves(root->left, result);
//     getLeaves(root->right, result);
// }

// // Helper function to get the right boundary (excluding leaves)
// void getRightBoundary(TreeNode* root, vector<int>& result) {
//     if (!root || (!root->left && !root->right)) return; // Skip leaves

//     if (root->right) getRightBoundary(root->right, result);
//     else if (root->left) getRightBoundary(root->left, result);
//     result.push_back(root->val); // Add after recursion to reverse the order
// }

// // Main function to get the boundary of the binary tree
// vector<int> boundaryOfBinaryTree(TreeNode* root) {
//     if (!root) return {};

//     vector<int> result;
//     result.push_back(root->val); // Add root

//     // Get left boundary (excluding leaves)
//     getLeftBoundary(root->left, result);

//     // Get leaves (left to right)
//     getLeaves(root->left, result); // Left subtree leaves
//     getLeaves(root->right, result); // Right subtree leaves

//     // Get right boundary (excluding leaves and root)
//     getRightBoundary(root->right, result);

//     return result;
// }

// int main() {
//     vector<int> levelOrderTree = {1, 2, 3, -1, 4, 5, 6};
//     TreeNode* root = createTreeLevelOrder(levelOrderTree);
//     cout << "Tree:" << endl;
//     printBTLevelWise(root);

//     vector<int> result = boundaryOfBinaryTree(root);
//     cout << "Boundary: ";
//     for (int i : result) cout << i << " ";
//     cout << endl;

//     return 0;
// }