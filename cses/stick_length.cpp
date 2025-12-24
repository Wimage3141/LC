#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    long long total_cost = 0;
    cin >> n;
    vector<int> arr(n);
    for(int& val : arr) cin >> val;
    
    sort(arr.begin(), arr.end());
    
    
    int mid = arr.size() / 2;
    int final_length = arr[mid];
    
    if(arr.size() % 2 == 1) {
        for(const int val : arr) total_cost += abs(val - final_length);
    } else {
        long long total_cost_1 = 0, total_cost_2 = 0;
        for(const int val : arr) total_cost_1 += abs(val - final_length);
        for(const int val : arr) total_cost_2 += abs(val - final_length);
        total_cost = max(total_cost_1, total_cost_2);
    }
    
    cout << total_cost << endl;
}

int main() {
    solve();
}