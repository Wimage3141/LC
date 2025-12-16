#include <iostream>

using namespace std;

int main() {
	int n;
	size_t d = 0;
	cin >> n;
	int prev_e;
	cin >> prev_e;
	while(--n) {
		int e;
		cin >> e;
		if(e < prev_e) {
			d += (prev_e - e);
		}
		else prev_e = e;
	}
	cout << d << endl;
}