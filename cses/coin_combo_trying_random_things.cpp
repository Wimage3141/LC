#include <iostream>
#include <vector>

using namespace std;

void solve() {
    const int P = 1e9 + 7;
    int n, target_sum;
    cin >> n >> target_sum;
    vector<int> coins(n);
    vector<int> ways(target_sum + 1, 0);
    for(int& coin : coins) cin >> coin;
    
    for(const int coin : coins) {
        for(int sum = 0; sum <= target_sum; sum++) {
            if(sum - coin == 0) ways[sum] = ( ways[sum] + 1 ) % P;
            else if(sum - coin > 0) ways[sum] = ( ways[sum] + ways[sum - coin] ) % P;
        }
    }
    
    cout << ways[target_sum] << endl;
}

int main() {
    solve();
}