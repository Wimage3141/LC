#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

Node* dfs(Node* node, unordered_map<Node*, Node*>& oldToNew) {
    if(oldToNew.find(node) != oldToNew.end()) return oldToNew[node];

    Node* newNode = new Node(node->val);
    vector<Node*> neighbors = node->neighbors;

    oldToNew[node] = newNode;

    for(auto neighbor : neighbors) {
        newNode->neighbors.push_back(dfs(neighbor, oldToNew));
    }

    return newNode;
}


Node* cloneGraph(Node* node) {
    if(!node) return nullptr;
    unordered_map<Node*, Node*> oldToNew;

    return dfs(node, oldToNew);
}



int main() {

}