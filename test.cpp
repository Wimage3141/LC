#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    template <typename T>
    void printVector(const vector<T>& v) {
        for (const auto& e : v)
            cout << e << " ";
        cout << endl;
    }
};

int main() {
    
}