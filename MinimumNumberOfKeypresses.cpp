#include <iostream>
#include <unordered_map>
using namespace std;

int minKeypresses(string message) {
	unordered_map<char, int> m;
	int press = 1;
	int numPress = 0;
	for(char c : message) {
		if(m.find(c) != m.end()) {
			numPress += m[c];
			continue;
		}

		if(m.size() < 9) press = 1;
		else if(m.size() < 18) press = 2;
		else press = 3;

		m[c] = press;
		numPress += m[c];
	}
	return numPress;
}

int main() {
	cout << minKeypresses("abcdefghijkl") << endl;
}