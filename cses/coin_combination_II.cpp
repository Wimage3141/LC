#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    const int P = 1e9 + 7;
    int n, target_sum;
    cin >> n >> target_sum;
    vector<int> coins(n);
    vector<vector<int> > ways(target_sum + 1, vector<int>(n, 0));
    for(int& coin : coins) cin >> coin;
    sort(coins.begin(), coins.end());
    
    for(int sum = 0; sum <= target_sum; sum++) {
        for(size_t coin_idx = 0; coin_idx < coins.size(); coin_idx++) {
            for(size_t j = coin_idx; j < coins.size(); j++) {
                if(sum - coins[j] == 0) ways[sum][coin_idx] = ( ways[sum][coin_idx] + 1 ) % P;
                else if(sum - coins[j] > 0) ways[sum][coin_idx] = ( ways[sum][coin_idx] + ways[sum - coins[j]][j] ) % P;
            }
        }
    }
    
    // cout << endl;
    // for(size_t r = 0; r < ways.size(); r++) {
    //     for(size_t c = 0; c < ways[0].size(); c++) {
    //         cout << ways[r][c] << " ";
    //     }
    //     cout << endl;
    // }
    cout << ways[target_sum][0] << endl;
}

int main() {
    solve();
}