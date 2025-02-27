#include <iostream>
#include <vector>

using namespace std;

void test(int index, vector<int>& nums, vector<int>& subset, vector<vector<int>>& allSubsets) {
	if(index >= nums.size()) {
		allSubsets.push_back(subset);
		return;
	}

	subset.push_back(nums[index]);
	test(index+1, nums, subset, allSubsets);
	subset.pop_back();

	test(index+1, nums, subset, allSubsets);
}

vector<vector<int>> combinationSum(vector<int>& nums, int target) {
	vector<int> subset;
	vector<vector<int>> allSubsets;
	vector<vector<int>> result;

	test(0, nums, subset, allSubsets);

	for(auto s : allSubsets) {
		int sum = 0;
		for(int num : s) sum += num;

			cout << "sum: " << sum << endl;
		if(sum == target) {
			for(int num : s) cout << num << " ";
			cout << "test? " << endl;
			result.push_back(s);
		}
	}

	return result;
}

int main() {
	vector<int> nums = {2, 5, 6, 9};
	vector<vector<int>> allSubsets;
	vector<int> subset;
	test(0, nums, subset, allSubsets);

	// for(auto sub : allSubsets) {
	// 	for(int num : sub) {
	// 		cout << num <<  " ";
	// 	}
	// 	cout << endl;
	// }
	
	vector<vector<int>> result;
	result = combinationSum(nums, 9);
	for(auto res : result) {
		for(int num : res) {
			cout << num << " ";
		}
		cout << endl;
	}
}