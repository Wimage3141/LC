#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    long long sum = INT_MIN, max_sum = INT_MIN;
    cin >> n;
    for(int i = 0; i < n; i++) {
        long long x;
        cin >> x;

        if(sum < 0 && x >= 0) {
            sum = x;
            max_sum = max(x, max_sum);
        }
        else if(sum < 0 && x < 0) {
            if(sum < x) {
                sum = x;
                max_sum = max(max_sum, x);
            }
            else {
                sum += x;
            }
        }
        else if(sum >= 0 && x >= 0) {
            sum += x;
            max_sum = max(max_sum, sum);
        }
        else {
            sum += x;
        }
    }
    cout << max_sum << endl;
}

int main() {
    solve();
}