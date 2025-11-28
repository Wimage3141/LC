#include <iostream>
using namespace std;

void solve() {
    int n;
    cin >> n;
    if(n == 1) {
	cout << 1 << endl;
	return;
    }
    if(n == 2) {
	cout << 9 << endl;
	return;
    }
    int x = (5 * n * n) - (5 * n) - 5;
    int y = (4 * n * n) - n - 4;
    cout << max(x, y) << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
	solve();
    }
}
