#include <iostream>
using namespace std;

void solve() {
    int n;
    cin >> n;

    long long ans = 1;
    long long X = 1000000007;

    for(int i = 1; i <= n; i++) {
	ans = ( (ans % X) * (2 % X) ) % X;
    }

    cout << ans << endl;
}

int main() {
    solve();
}
