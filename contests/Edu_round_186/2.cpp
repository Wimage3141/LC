#include <iostream>

using namespace std;

void solve() {
    int a_inp, b_inp, a, b;
    cin >> a_inp >> b_inp;
    a = min(a_inp, b_inp);
    b = max(a_inp, b_inp);
    
    bool first = true;
    int subtract = 1, layers = 0;
    while(a >= 0 && b >= 0) {
        if(first) {
            if(a - subtract >= 0) layers++;
            else break;
            a -= subtract;
            first = false;
        }
        else {
            if(b - subtract >= 0) layers++;
            else break;
            b -= subtract;
            first = true;
        }
        subtract *= 2;
    }
    
    int layers_2 = 0;
    first = false;
    subtract = 1;
    a = min(a_inp, b_inp);
    b = max(a_inp, b_inp);
    
    while(a >= 0 && b >= 0) {
        if(first) {
            if(a - subtract >= 0) layers_2++;
            else break;
            a -= subtract;
            first = false;
        }
        else {
            if(b - subtract >= 0) layers_2++;
            else break;
            b -= subtract;
            first = true;
        }
        subtract *= 2;
    }
    // cout << "layers: " << layers << endl;
    // cout << "layers_2: " << layers_2 << endl;
    int max_layers = max(layers, layers_2);
    cout << max_layers << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}