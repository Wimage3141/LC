#include <iostream>
#include <vector>

using namespace std;

long long dice(long long sum) {
    if(sum == 0) return 0;
    int ways = 0;
    for(int num = 1; num <= 6; num++) {
        if(sum - num >= 0) {
            ways += dice(sum - num) + 1;
        }
    }
    return ways;
}

void solve() {
    int n;
    cin >> n;
    int ans = dice(n);
    cout << ans << endl;
}

int main() {
    solve();
}