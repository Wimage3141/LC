#include <iostream>
#include <vector>
 
using namespace std;
 
void solve() {
    const long long P = 1e9 + 7;
    int n;
    cin >> n;
    vector<long long> values(n + 1, 0);
    for(long long sum = 1; sum <= n; sum++) {
        for(int num = 1; num <= 6; num++) {
            if(sum - num == 0) {
                values[sum] = ( values[sum] + 1 ) % P;
            }
            else if(sum - num >= 0 && values[sum - num] != 0) {
                values[sum] = ( values[sum] + values[sum - num] ) % P;
            }
        }
    }

    cout << values[n] << endl;
}
 
int main() {
    solve();
}
