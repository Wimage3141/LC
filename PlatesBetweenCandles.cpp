#include <bits/stdc++.h>
using namespace std;


vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
    int n = s.size();
    vector<int> left(n, -1);
    vector<int> right(n, -1);
    vector<int> prefixSum(n, 0);
    vector<int> answer;
    int sum = 0;

    int prevCandleIndex = -1;
    int nextCandleIndex = -1;
    for(int i = 0; i < n; i++) {
        if(s[i] == '|') {
            prevCandleIndex = i;
        }
        left[i] = prevCandleIndex;

        if(s[i] == '*') {
            sum++;
        }
        prefixSum[i] = sum;
    }

    for(int i = n - 1; i >= 0; i--) {
        if(s[i] == '|') {
            nextCandleIndex = i;
        }
        right[i] = nextCandleIndex;
    }

    for(const auto& query : queries) {
        int l = query[0], r = query[1];

        int rightCandleIndex = right[l];
        int leftCandleIndex = left[r];

        if(leftCandleIndex == -1 || rightCandleIndex == -1 || rightCandleIndex >= leftCandleIndex) {
            answer.push_back(0);
            continue;
        }
        int plateCount = prefixSum[leftCandleIndex] - prefixSum[rightCandleIndex];
        answer.push_back(plateCount);
    }
    return answer;
}


int main() {
    
}