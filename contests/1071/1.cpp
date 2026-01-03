#include <iostream>

using namespace std;

void solve() {
    int k, x;
    cin >> k >> x;
    // Starting from a letter s_i, if x reaches another letter s_j that is the same,
    // then the string is not valid
    
    cout << (x * k + 1) << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}