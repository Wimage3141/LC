#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    long long n, x;
    cin >> n >> x;
    vector<pair<long long, int>> a(n);
    int i = 0;
    for(auto& val : a) {
        cin >> val.first;
        val.second = i;
        i++;
    }
    
    sort(a.begin(), a.end());
    
    int l = 0, r = a.size() - 1;
    while(l < r) {
        if(a[l].first + a[r].first < x) l++;
        else if(a[l].first + a[r].first > x) r--;
        else {
            cout << (a[l].second + 1) << " " << (a[r].second + 1) << endl;
            return;
        }
    }
    cout << "IMPOSSIBLE" << endl;
}

int main() {
    solve();
}