#include <iostream>
using namespace std;

long long nC2(long long n) {
    long long ans = n * (n - 1);
    ans /= 2;
    return ans;
}

void solve() {
	long long n;
	cin >> n;
	if(n <= 0) return;
	cout << 0 << endl;
	if(n == 1) return;
	cout << 6  << endl;
	if(n == 2) return;

	long long i = 3;
	n -= 2;

	while(n--) {
		unsigned long long x = i * i;
		unsigned long long total = nC2(x);
		unsigned long long knight_attack_C = 4 * (i - 2) * (i - 1);
		unsigned long long ans = total - knight_attack_C;
		cout << ans << endl;
		i++;
	}
}

int main() {
	solve();
}