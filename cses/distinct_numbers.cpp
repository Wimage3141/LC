#include <iostream>
#include <set>
using namespace std;

void solve() {
    int n;
    cin >> n;
    set<int> s;
    while(n--) {
        int x;
        cin >> x;
        s.insert(x);
    }
    cout << s.size() << endl;
}

int main() {
    solve();
}

