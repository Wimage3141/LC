#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int n, x, cnt = 0;
    cin >> n >> x;

    vector<int> weight(n);

    for(int &w : weight) cin >> w;

    sort(weight.begin(), weight.end());

    int l = 0, r = weight.size() - 1;

    while(l <= r) {
        if(weight[l] + weight[r] <= x) {
            cnt++;
            l++;
            r--;
        }
        else if(weight[r] <= x) {
            cnt++;
            r--;
        }
        else if(l == r) {
            if(weight[l] <= x) cnt++;
            break;
        }
        else r--;
    }

    cout << cnt << endl;
}

int main() {
    solve();
}
