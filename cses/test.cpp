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
    vector<int> v = {24, 7, -27, 17, -67, 65, -23, 58, 85, -39};
    int sum = 0;
    for(size_t i = 0; i < 5; i++) {
        sum += v[i];
    }
    cout << sum << endl;
    cout << (65 - 23 + 58 + 85) << endl;
}

int main() {
    solve();
}