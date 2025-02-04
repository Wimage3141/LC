#include <iostream>
#include <vector>
using namespace std;

void merge(int left, int mid, int right, vector<int>& arr) {
	int leftSize = mid - left + 1;
	int rightSize = right - mid;

	vector<int> L(leftSize), R(rightSize);

	for(int i = 0; i < leftSize; i++) {
		L[i] = arr[left + i];
	}

	for(int i = 0; i < right; i++) {
		R[i] = arr[mid + 1 + i];
	}

	int i = 0, j = 0, k = left;
	while(i < leftSize && j < rightSize) {
		if(L[i] < R[j]) {
			arr[k] = L[i];
			i++;
		}
		else if(R[j] < L[i]) {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while(i < leftSize) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while(j < rightSize) {
		j++;
		k++;
	}
}

void mergeSort(int left, int right, vector<int>& arr) {
	if(left == right) return;

	int mid = left + (right - left) / 2;

	mergeSort(left, mid, arr);
	mergeSort(mid+1, right, arr);

	merge(left, mid, right, arr);
}

void printArr(const vector<int>& arr) {
	for(int i : arr) cout << i << " ";
	cout << endl;
}

int main() {
	vector<int> v{4, 2, 7, 1, 3, 6, 5};
	
	cout << "before sorting: " << endl;
	printArr(v);

	cout << "after sorting: " << endl;
	mergeSort(0, v.size() - 1, v);
	printArr(v);

}