#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int rounds_num = 1;
    vector<int> arr(n + 1);
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        arr[x] = i;
    }
    
    for(int i = 2; i <= n; i++) {
        if(arr[i] < arr[i - 1]) rounds_num++;
    }
    
    cout << rounds_num << endl;
}
 int main() {
    solve();
}