#include <iostream>
using namespace std;

int main() 
{
	int n;
	cin >> n;
	if(n == 1) cout << "1" << endl;
	else if(n <= 3) cout << "NO SOLUTION\n";
	else if(n == 4) cout << "2 4 1 3" << endl;
	else {
		for(int i = n; i > 0; i -= 2) {
			cout << i << " ";
		}
		for(int i = n - 1; i > 0; i -= 2) {
			cout << i << " ";
		}
	}
}