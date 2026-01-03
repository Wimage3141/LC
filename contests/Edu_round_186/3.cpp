#include <iostream>
#include <vector>
#include <set>

using namespace std;

void solve() {
    long long n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    set<int> incorrect_count;
    for(int& val : a) cin >> val;
    for(int& val : b) cin >> val;
    for(int& val : c) cin >> val;
    
    long long p = n;
    long long bad1 = 0, bad2 = 0;
    
    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < n; j++) {
    //         if(a[i] >= b[j]) incorrect_count.insert(j - i);
    //     }
    // }
    bool good;
    int good_param1 = 0, good_param2 = 0;
    
    for(int i = 0; i < n; i++) {
        good = true;
        for(int j = 0; j < n; j++) {
            if( a[j] >= b[ (j + i) % n ] ) {
                good = false;
            }
        }
        if(good) good_param1++;
    }
    
    for(int i = 0; i < n; i++) {
        good = true;
        for(int j = 0; j < n; j++) {
            if( b[j] >= c[ (j + i) % n ] ) {
                good = false;
            }
        }
        if(good) good_param2++;
    }
    // cout << "good_param2: " << good_param2 << endl;
    
    p = n * good_param1 * good_param2;
    
    
    
    cout << p << endl;
    
    // long long SIZE = incorrect_count.size() + 0LL;
    // p = max(p * (n - SIZE), 0LL);
    // incorrect_count.clear();
    
    // for(int i = 0; i < n; i++) {
    //     for(int j = 0; j < n; j++) {
    //         if(b[i] >= c[j]) incorrect_count.insert((j - i));
    //     }
    // }
    // SIZE = incorrect_count.size() + 0LL;
    // p = max(p * (n - SIZE), 0LL);
    
    // cout << p << endl;
}
    /*
1 5
1 4 2 3 5
6 4 5 7 6
7 5 8 10 10
     */

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
/*
5
2
1 2
3 4
5 4
3
1 1 1
2 2 2
3 3 3
4
1 2 1 2
3 3 2 2
5 5 5 5
5
1 4 2 3 5
6 4 5 7 6
7 5 8 10 10
2
1 1
1 1
1 1
 */