#include <iostream>
#include <cmath>
using namespace std;

void solve() {
	long long x, y;
	cin >> y >> x;

	long long n = max(x, y);
	long long num = 1ULL * (n - 1) * (n - 1);

	if(n & 1) {
		// if odd, then counterclockwise spiral
		long long start_x = 1, start_y = n;
		long long change_x = abs(x - start_x), change_y = abs(y - start_y);
		num += change_x + change_y + 1;
	}


	else {
		// if even, then clockwise spiral
		long long start_x = n, start_y = 1;
		long long change_x = abs(x - start_x), change_y = abs(y - start_y);
		num += change_x + change_y + 1;
	}

	cout << num << endl;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}