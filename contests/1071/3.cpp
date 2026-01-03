#include <climits>
#include <iostream>

using namespace std;

void solve() {
    int n, smallest = INT_MAX, second_smallest = INT_MAX;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(x < smallest) {
            second_smallest = smallest;
            smallest = x;
        }
        else if(x < second_smallest) second_smallest = x;
    }

    cout << max(smallest, second_smallest - smallest) << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}