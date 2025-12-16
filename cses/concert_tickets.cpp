#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

void solve() {
    int n, m, h, t;
    cin >> n >> m;
    multiset<int> tickets;
    vector<int> results;
    
    for(int i = 0; i < n; i++) {
        cin >> h;
        tickets.insert(h); // red black tree, already sorted
    }
    
    for(int i = 0; i < m; i++) {
        cin >> t;
        auto it = tickets.upper_bound(t);
        if(it == tickets.begin()) results.push_back(-1);
        else {
            results.push_back(*(--it));
            tickets.erase(it);
        }
    }
    
    for(int r : results) cout << r << endl;
}

int main() {
    solve();
}
