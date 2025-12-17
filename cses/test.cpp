#include <algorithm>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

bool cmp(pair<long long, long long> a,
         pair<long long, long long> b) { // comparator
             if(a.second == b.second) return a.first < b.first;
             return a.second < b.second;
}

void solve() {
    
    vector<pair<long long, long long>> v = {{2, 3}, {2, 4}, {5, 9}, {3, 7}, {6, 8}, {9, 10}, {1, 5}};
    sort(v.begin(), v.end(), cmp);
    
    for(auto a : v) cout << a.second << endl;
}

int main() {
    solve();
}