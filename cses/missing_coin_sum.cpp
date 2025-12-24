#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int& val : arr) cin >> val;
    
    sort(arr.begin(), arr.end());
    
    long long prefix_sum = 0;
    for(size_t i = 0; i < arr.size(); i++) {
        if(prefix_sum < arr[i] && arr[i] - prefix_sum > 1) {
            cout << (prefix_sum + 1) << endl;
            return;
        }
        prefix_sum += arr[i];
    }
    cout << (prefix_sum + 1) << endl;
}

int main() {
    solve();
}