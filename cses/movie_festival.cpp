#include <climits>
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<long long, long long>> times;
    for(int i = 0; i < n; i++) {
        long long start, end;
        cin >> start >> end;
        times.push_back({start, end});
    }
    
    sort(times.begin(), times.end(),
        [](pair<long long, long long> a, pair<long long, long long> b) {
            if(a.second == b.second) return a.first < b.first;
            return a.second < b.second;
        }
    );
    
    int movies_watched = 1;
    auto prev_time = times[0];
    for(size_t i = 1; i < times.size(); i++) {
        if(times[i].first >= prev_time.second) {
            movies_watched++;
            prev_time = times[i];
        }
    }
    
    cout << movies_watched << endl;
}

int main() {
    solve();
}