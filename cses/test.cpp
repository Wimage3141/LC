#include <algorithm>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

void solve() {
    multiset<int> s;
    s.insert(2);
    s.insert(4);
    s.insert(5);
    s.insert(9);
    
    // 5 3 4 5 8
    // 3 5 5 7 8
    // 4 8 3
    // tickets.upper_bound(4)
    // if upper_bound points to the first iterator, that means the price of the cheapest ticket available
    // if upper_bound points to first iterator:
    //      price of cheapest ticket > price the customer is willing to pay --> -1 (customer cannot get any ticket)
    // 
    // how do we check if the iterator is pointing to the first element of the multiset?
    // 
    // if tickets.upper_bound() == tickets.begin():
    // then 
    
    auto it = s.upper_bound(6); // first iterator that is STRICTLY greater than 6
    cout << *it << endl;
}

int main() {
    solve();
}