#include <iostream>
#include <vector>
using namespace std;

vector<bool> is_present(10, false);

int main() {
    int n, cnt = 0;
    cin >> n;
    while(n--) {
	int x;
	cin >> x;
	is_present[x] = is_present[x] | true;
    }
    
    for(int i = 0; i < 10; i++) {
	if(is_present[i] == true) cnt++;
    }
    cout << cnt << endl;
}
