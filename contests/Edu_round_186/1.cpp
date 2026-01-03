#include <iostream>
#include <string>

using namespace std;

void solve() {
    int n;
    cin >> n;
    if(n < 4) {
        cout << 0 << endl;
        return;
    }
    string s;
    for(int i = 0; i < n; i++) {
        char c;
        cin >> c;
        s.push_back(c);
    }
    int times = 0;
    
    for(size_t i = 0; i < s.size(); i++) {
        if(s[i] == '2' && i < (s.size() - 3) ) {
            if(s[i + 1] == '0' && s[i + 2] == '2' && s[i + 3] == '6') {
                cout << 0 << endl;
                return;
            }
        }
    }
    
    for(size_t i = 0; i < s.size(); i++) {
        if(s[i] == '2' && i < (s.size() - 3) ) {
            if(s[i + 1] == '0' && s[i + 2] == '2' && s[i + 3] == '5') {
                times++;
                break;
            }
        }
    }
    cout << times << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}