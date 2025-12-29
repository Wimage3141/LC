#include <iostream>
#include <vector>

using namespace std;

void solve() {
    const long long P = 1e9 + 7;
    int n, target_sum;
    cin >> n >> target_sum;
    vector<long long> coins(n);
    vector<long long> ways(target_sum + 1, 0);
    for(long long& coin : coins) cin >> coin;
    
    for(int sum = 1; sum <= target_sum; sum++) {
        for(const int coin : coins) {
            if(sum - coin == 0) ways[sum] = ( ways[sum] + 1 ) % P;
            else if(sum - coin > 0) ways[sum] = ( ways[sum] + ways[sum - coin] ) % P;
        }
    }
    cout << ways[target_sum] << endl;
}

int main() {
    solve();
}