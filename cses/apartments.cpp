#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    long long n, m, k, cnt = 0;
    size_t i = 0, j = 0;
    vector<long long> req;
    vector<long long> apt;
    cin >> n >> m >> k;
    while(n--) {
        long long x;
        cin >> x;
        req.push_back(x);
    }

    while(m--) {
        long long x;
        cin >> x;
        apt.push_back(x);
    }

    sort(req.begin(), req.end());
    sort(apt.begin(), apt.end());
    
    while( j < apt.size() && i < req.size() ) {
        cout << endl;
        if( abs(req[i] - apt[j]) <= k ) {
            cnt++;
            i++;
            j++;
        }
        else if( (req[i] + k) < apt[j] ) i++;
        else j++;
    }

   cout << cnt << endl;
}

int main() {
    solve();
}