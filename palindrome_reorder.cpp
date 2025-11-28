#include <iostream>
#include <unordered_map>
using namespace std;

/*
Missed an opportunity to optimize the program, to generate a repeated pattern of characters, I used a while loop instead like so
while(cnt > 0) {
result += ch + result;
cnt -= 2;
}
instead of 
result += ch + string(cnt / 2, ch);
*/

void solve() {
    string str, result;
    int odd_ch_cnt = 0;
    char odd_ch;
    cin >> str;
    unordered_map<char, int> m;

    for(char ch : str) {
	m[ch]++;
    }

    if(m.size() == 1) {
	cout << str;
	return;
    }

    for(const auto& [ch, cnt] : m) {
	if(cnt & 1) {
	    odd_ch_cnt++;
	    odd_ch = ch;
	}
    }

    if(str.size() & 1 && odd_ch_cnt > 1) {
	cout << "NO SOLUTION" << endl;
	return;
    }
    else if( !(str.size() & 1) && odd_ch_cnt > 0) {
	cout << "NO SOLUTION" << endl;
	return;
    }

    if(odd_ch_cnt == 1) {
	result += odd_ch;
	m[odd_ch]--;
    }

    for(auto& [ch, cnt] : m) {
	result = string(cnt / 2, ch) + result;
	result = result + string(cnt / 2, ch);
    }

    cout << result << endl;
}

int main() {
    solve();
}
