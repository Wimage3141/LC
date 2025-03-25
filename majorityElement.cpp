#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int computeFrequency(int target, int left, int right, vector<int>& arr) {
    int cnt = 0;
    for (int i = left; i <= right; i++) {
        if (arr[i] == target) cnt++;
    }
    return cnt;
}
int solDACHelper(int left, int right, vector<int>& arr) {
    if (left == right) return arr[left];
    int mid = left + ((right - left) / 2);
    int majorityLeft = solDACHelper(left, mid, arr);
    int majorityRight = solDACHelper(mid + 1, right, arr);
    if (majorityLeft == majorityRight) return majorityLeft;
    int leftCount = computeFrequency(majorityLeft, left, right, arr);
    int rightCount = computeFrequency(majorityRight, left, right, arr);
    return (leftCount > rightCount) ? majorityLeft : majorityRight;
}
int solDAC(vector<int>& arr) {
    int n = arr.size();
    int majority = solDACHelper(0, n - 1, arr);
    
    int finalCount = computeFrequency(majority, 0, n - 1, arr);
    
    return (finalCount > (n/2)) ? majority : -1;
}