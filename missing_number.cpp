#include <iostream>

using namespace std;

int main() {
	long n;
	cin >> n;
	long n_sum = ( n * (n + 1) ) / 2;
	long sum = 0;
	while(--n) {
		int x;
		cin >> x;
		sum += x;
	}
	cout << (n_sum - sum);
}