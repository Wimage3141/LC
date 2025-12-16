#include <iostream>
using namespace std;

void solve() {
    long long n, m, X = 3;
    cin >> n >> m;
    if(n == 0 && m == 0) cout << "YES" << endl;
    else if(n == 0 || m == 0) cout << "NO" << endl;
    else if( max(m, n) / min(m, n) > 2
	    || (max(m, n) / min(m, n) == 2
	    && max(m, n) % min(m, n) != 0)
	    ) cout << "NO" << endl;
    else if( (m + n) % X == 0 ) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
	solve();
    }
}
