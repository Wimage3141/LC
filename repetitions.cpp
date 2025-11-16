#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	size_t rep = 1, max_rep = 1; 
	string input;
	getline(cin, input);

	for(size_t i = 0; i < input.size() - 1; i++) {
		if(input[i] == input[i + 1]) {
			rep++;
			max_rep = max(rep, max_rep);
		}
		else {
			rep = 1;
		}
	}

	cout << max_rep;
}

// ATTCGGGGGA