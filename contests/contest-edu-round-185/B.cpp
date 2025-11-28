#include <climits>
#include <iostream>
using namespace std;

// Almost solved this :'(
// The key was realizing that the max 'span' (r-l+1) can be substracted from the sum
// to see if we have enough 'moves' for the remaining n-1 moves (since exactly n moves
// need to be made and the first move with max span already counts as one
// Also, span can be at max, the number of non-zero elements in the array, so if 
// span > #non-zero elements, we take the number of non-zero elements instead,
// hence, min(span, non_zero_cnt)

void solve() {
    int n, zero_cnt = 0, sum = 0;
    cin >> n;
    int b_arr_size = n;
    while(n--) {
	int x;
	cin >> x;
	if(x == 0) zero_cnt++;
	sum += x;
    }
    int span = sum - b_arr_size + 1;
    int non_zero_cnt = b_arr_size - zero_cnt;
    int ans = min(span, non_zero_cnt);
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
	solve();
    }
}
