#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void solve() {
    int n, curr_customer = 0, max_cust = 0;
    cin >> n;
    vector<pair<int, int>> times;
    
    for(int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        times.push_back({start, 1});
        times.push_back({end, -1});
    }
    
    sort(times.begin(), times.end());
    
    for(const auto& time : times) {
        curr_customer += time.second;
        max_cust = max(max_cust, curr_customer);
    }
    
    cout << max_cust << endl;
}

int main() {
    solve();
}