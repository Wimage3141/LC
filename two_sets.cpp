#include <iostream>
#include <set>

using namespace std;

void solve() {
	long long n;
	cin >> n;
	set<long long> s;
	
	long long sum = (n * (n + 1) ) / 2; // my code was failing because I initialized n as int and when n * (n + 1) happened,
					    // it would overflow before it could be converted to long long.
	if(sum & 1) {
		cout << "NO" << endl;
		return;
	}
	else {
		cout << "YES" << endl;
		// sum is even
		long long target = sum / 2;
		long long i = n;
		while(target) {
			if( (target - i) >= 0) {
				target -= i;
				s.insert(i);
			}
			i--;
		}
		cout << s.size() << endl;
		for(long long x : s) {
			cout << x << " ";
		}
		cout << endl;
		
		cout << (n - s.size()) << endl;
		for(long long i = 1; i <= n; i++) {
			if(s.find(i) == s.end()) {
				cout << i << " ";
			}
		}
	}
}

int main() {
	solve();
}
