#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> findTopSortOrder(int numVertex, vector<vector<int>>& graph) {
	vector<int> ordering;
	vector<int> inDegree(numVertex);

	for(int currVertex = 0; currVertex < numVertex; currVertex++) {
		for(int child : graph[currVertex]) {
			inDegree[child]++;
		}
	}

	for(int i = 0; i < inDegree.size(); i++) {
		cout << "inDegree[" << i << "]: " << inDegree[i] << endl;
	}

	queue<int> q;

	for(int i = 0; i < inDegree.size(); i++) {
		if(inDegree[i] == 0) {
			q.push(i);
		}
	}



	while(!q.empty()) {
		int currVertex = q.front();
		q.pop();
		ordering.push_back(currVertex);
		for(int child : graph[currVertex]) {
			inDegree[child]--;
			if(inDegree[child] == 0) q.push(child);
		}
	}
	return ordering;
}

int main() {
	int numVertex = 7;
	vector<vector<int>> graph = {
		{1, 2}, // 0
		{3}, // 1
		{3}, // 2
		{4}, // 3
		{5}, // 4
		{6}, // 5
		{} // 6
	};

	int numVertex2 = 6;
	vector<vector<int>> graph2 = {
		{1, 2},
		{3},
		{3},
		{4},
		{5},
		{3}
	};

	vector<int> ordering = findTopSortOrder(numVertex2, graph2);
	cout << "ordering size: " << ordering.size() << endl;
	cout << "numVertex: " << numVertex << endl;
	if(ordering.size() != numVertex) {
		cout << "Cycle detected!" << endl;
		return 0;
	}
	for(int e : ordering) cout << e << " ";
	cout << endl;
}