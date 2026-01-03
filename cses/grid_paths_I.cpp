#include <iostream>
#include <vector>

using namespace std;

void solve() {
    const int MOD = 1e9 + 7;
    int n;
    cin >> n;

    vector<vector<int> > paths(n, vector<int>(n, 0));
    vector<vector<char> > grid(n, vector<char>(n, '.'));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            char c;
            cin >> c;
            if(c == '*') grid[i][j] = '*';
        }
    }

    // initialize first row
    for(int c = 0; c < n; c++) {
        if(grid[0][c] == '*') break;
        paths[0][c] = 1;
    }

    // initialize first column
    for(int r = 0; r < n; r++) {
        if(grid[r][0] == '*')
            break;
        paths[r][0] = 1;
    }
    
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < n; j++) {
            if(grid[i][j] == '*') continue;
            paths[i][j] = ((paths[i][j] % MOD) + (paths[i - 1][j] % MOD) + (paths[i][j - 1] % MOD)) % MOD;
        }
    }
    cout << paths[n - 1][n - 1] << endl;
}

int main() {
    solve();
}