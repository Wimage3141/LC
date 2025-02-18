class Solution {
public:
    bool dfs(int source, vector<vector<int>>& graph, vector<bool>& check1, vector<bool>& check2) {
        check1[source] = true;
        bool noLoop = true;
        
        for(auto child : graph[source]) {
            if(check1[child] && !check2[child]) {
                noLoop &= false;
                continue;
            }
            if(check1[child] && check2[child]) continue;
            noLoop &= dfs(child, graph, check1, check2);
        }
        check2[source] = true;

        return noLoop;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<bool> check1(numCourses, false);
        vector<bool> check2(numCourses, false);
        for(int i = 0; i < prerequisites.size(); i++) {
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        // for(int i = 0; i < numCourses; i++) {
        //     cout << i << ": ";
        //     for(auto child : graph[i]) {
        //         cout << child << " ";
        //     }
        //     cout << endl;
        // }

        int canFinish = true;

        for(int i = 0; i < numCourses; i++) {
            canFinish &= dfs(i, graph, check1, check2);
        }

        return canFinish;
    }
};