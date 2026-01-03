#include <climits>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> steps(n);
    steps[0] = 0;
    for(int i = 1; i <= n; i++) {
        int num = i, max_digit = INT_MIN;
        while(num != 0) {
            int curr_digit = num % 10;
            max_digit = max(max_digit, curr_digit);
            num /= 10;
        }
        if(i - max_digit == 0) steps[i]++;
        else if(i - max_digit > 0) steps[i] += steps[i - max_digit];
    }
    for(int step : steps) cout << step << " ";
    cout << endl;
    cout << endl;
    cout << steps[n] << endl;
}

int main() {
    solve();
}