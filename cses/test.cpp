#include <algorithm>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

void solve() {
    multiset<int> s;
    s.insert(4);
    s.insert(5);
    s.insert(7);
    s.insert(9);
    
    auto it = s.lower_bound(5); // first iterator that is STRICTLY greater than 6
    cout << *it << endl;
    
    
}

int main() {
    solve();
}