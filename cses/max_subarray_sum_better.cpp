#include <climits>
#include <iostream>

using namespace std;

void solve() {
    int n;
    long long sum = LLONG_MIN, max_sum = LLONG_MIN;
    cin >> n;
    for(int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        
        if(i == 0)
            sum = x;
        else
            sum = max(x, sum + x);
        
        max_sum = max(max_sum, sum);
    }
    cout << max_sum << endl;
}

int main() {
    solve();
}