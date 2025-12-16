#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

void solve() {
    int n, m, h, t;
    cin >> n >> m;
    multiset<int> tickets;
    
    for(int i = 0; i < n; i++) {
        cin >> h;
        tickets.insert(h);  // Balanced binary tree, already sorted
    }
    
    for(int i = 0; i < m; i++) {
        cin >> t;
        auto it = tickets.upper_bound(t);
        if(it == tickets.begin()) cout << -1 << endl;
        else {
            it--;
            cout << *it << endl;
            tickets.erase(it);
        }
    }
}

int main() {
    solve();
}
