#include <iostream>
#include <vector>

using namespace std;

int dfs(int currVertex, int index, vector<int>& ordering, vector<bool>& visited, vector<vector<int>>& edges) {
	visited[currVertex] = true;
	for(auto child : edges[currVertex]) {
		if(!visited[child])
			index = dfs(child, index, ordering, visited, edges);
	}

	ordering[index] = currVertex;
	return index - 1;
}

vector<int> topSort(int numVertex, vector<vector<int>>& edges) {
	vector<int> ordering(numVertex); // topological ordering
	vector<bool> visited(numVertex, 0);

	int index = numVertex - 1;
	for(int i = 0; i < numVertex; i++) {
		if(!visited[i])
			index = dfs(i, index, ordering, visited, edges);
	}

	return ordering;
}






















int dfs2(int index, int currVertex, vector<bool>& visited, vector<vector<int>>& edges, vector<int>& ordering) {
	visited[currVertex] = true;
	for(auto child : edges[currVertex]) {

	}
}

vector<int> topSort2(int numVertex, vector<vector<int>>& edges) {
	vector<int> ordering; // topological ordering 
	vector<bool> visited(numVertex, false);
	int index = numVertex - 1;

	for(int i = 0; i < numVertex; i++) {
		if(visited[i]) continue;
		index = dfs(index, i, visited, edges, ordering);
	}

	return ordering;
}

int main() {

}