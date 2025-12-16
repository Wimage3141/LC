#include <iostream>
using namespace std;

void solve() {
    int n, y ,r;
    cin >> n >> y >> r;
    cout << min(n, r + (y / 2)) << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
	solve();
    }
}
