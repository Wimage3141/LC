#include <iostream>

using namespace std;

/*
    3
   / \
   2 1
   \ /
    0

3: 2, 1
2: 0
1: 0
0: 
*/

// Initiailize the graph
void graph_init(vector<vector<int>> &graph, vector<vector<int>> &prerequisites) {
    for(const auto prerequisite : prerequisites) {
        graph[prerequisite[1]].push_back(prerequisite[0]);
    }
}

void graph_traversal_dfs() {
    
}

int main() {

}