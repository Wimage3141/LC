#include <iostream>
#include <map>
#include <climits>

using namespace std;

void solve() {
    int n;
    cin >> n;
    map<int, int> m;
    m[0] = INT_MIN;
    int rounds_num = 1;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        m[x] = i;
    }
    
    // cout << "test: " << endl;
    // for(int i = 0; i <= n; i++) {
    //     cout << m[i] << " ";
    // }
    // cout << endl;
    // cout << "test: " << endl;
    
    for(int i = 1; i <= n; i++) {
        if(m[i] < m[i - 1]) rounds_num++;
    }
    
    cout << rounds_num << endl;
    // 4 2 1 5 3
    // (1, 4), (2, 2), (3, 1), (4, 5), (5, 3)
    // (0, INT_MIN), (4, 1), (2, 2), (1, 3), (5, 4), (3, 5)
    // round_num = 1
    // (0, INT_MIN), (1, 3), (4, 1), (2, 2), (5, 4), (3, 5)
}

int main() {
    solve();
}