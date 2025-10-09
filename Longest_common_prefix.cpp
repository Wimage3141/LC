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

    string longestCommonPrefix(vector<string>& strs) {
        string commonPrefix;
        int currCharIndex = 0;
        char currChar = strs[0][0];
        
        // Iterate over all chars of the first string
        for(currCharIndex = 0; currCharIndex < strs[0].size(); currCharIndex++) {
            currChar = strs[]
        }
    }
};

int main() {
    
}