#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void solve() {
    int n, ans = 0;
    cin >> n;
    vector<int> freq(10, 0);

    for(int i = 0; i < 2 * n; i++) {
	int x;
	cin >> x;
	freq[x]++;
    }
    
    int even_cnt = 0;
    bool at_least_one_1 = false;
    for(int i = 0; i < 10; i++) {
	if(freq[i] > 0) {
	    if(freq[i] == 1) at_least_one_1 = true;
	    if(freq[i] % 2 == 1) ans++;
	    else {
		if( (freq[i] / 2) % 2 == 1) ans += 2;
		else even_cnt++;
	    }
	}
    }
    if(even_cnt == 1 && at_least_one_1) {
	ans += 2;
    }
    else if(even_cnt % 2 == 0) {
	even_cnt *= 2;
	ans += even_cnt;
    }
    else {
	even_cnt -= 1;
	even_cnt *= 2;
	ans += even_cnt;
    }

    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
	solve();
    }
}
