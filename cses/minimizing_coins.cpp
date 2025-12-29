#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void solve() {
    int n, target_sum;
    cin >> n >> target_sum;
    vector<int> coins(n);
    vector<long long> values(target_sum + 1, INT_MAX / 2);
    for(int& coin : coins) cin >> coin;
    values[0] = 0;
    for(int sum = 1; sum <= target_sum; sum++) {
        for(const int& coin : coins) {
            if(sum - coin >= 0) values[sum] = min(values[sum - coin] + 1, values[sum]);
        }
    }
    
    if (values[target_sum] == (INT_MAX / 2) ) cout << -1 << endl;
    else cout << values[target_sum] << endl;
}

int main() {
    solve();
}