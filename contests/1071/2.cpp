#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int& val : a) cin >> val;
    
    vector<int> before(n, 0), after(n, 0);
    
    for(int i = 1; i < n; i++) {
        before[i] = before[i - 1] + abs(a[i] - a[i - 1]);
    }

    for(int i = n - 2; i >= 0; i--) {
        after[i] = after[i + 1] + abs(a[i + 1] - a[i]);
    }
    
    int min_time = min(before[n - 1] - abs(a[1] - a[0]), before[n - 1] - abs(a[n - 1] - a[n - 2]));
    for(int i = 1; i < n - 1; i++) {
        min_time = min(min_time, before[i - 1] + abs( a[i + 1] - a[i - 1] ) + after[i + 1]);
    }
    
    cout << min_time << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}