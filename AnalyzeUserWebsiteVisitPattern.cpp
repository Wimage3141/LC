#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
#include <sstream>
using namespace std;

// apparently correct, I HATE THIS PROBLEM
vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
    // Step 1: Group visits by user and sort by timestamp
    unordered_map<string, vector<pair<int, string>>> user_visits;
    for (size_t i = 0; i < username.size(); i++) {
        user_visits[username[i]].push_back({timestamp[i], website[i]});
    }

    // Step 2: Sort visits by timestamp for each user
    for (auto& [user, visits] : user_visits) {
        sort(visits.begin(), visits.end());
    }

    // Step 3: Generate all 3-sequences for each user and count their frequency
    map<vector<string>, int> sequence_count;
    for (const auto& [user, visits] : user_visits) {
        if (visits.size() < 3) continue; // Skip users with fewer than 3 visits

        // Extract websites in chronological order
        vector<string> sites;
        for (const auto& [time, site] : visits) {
            sites.push_back(site);
        }

        // Generate all 3-sequences using a set to avoid duplicates for the same user
        for (size_t i = 0; i < sites.size(); i++) {
            for (size_t j = i + 1; j < sites.size(); j++) {
                for (size_t k = j + 1; k < sites.size(); k++) {
                    vector<string> seq = {sites[i], sites[j], sites[k]};
                    sequence_count[seq]++;
                }
            }
        }
    }

    // Step 4: Find the most frequent 3-sequence
    vector<string> result;
    int max_count = 0;
    for (const auto& [seq, count] : sequence_count) {
        if (count > max_count || (count == max_count && seq < result)) {
            max_count = count;
            result = seq;
        }
    }

    return result;
}

vector<string> stringToArray(string str) {
	vector<string> splitStr; 
	istringstream iss(str);
	string word;
	while(iss >> word) {
		splitStr.push_back(word);
	}
	return splitStr;
} 

vector<string> mostVisitedPatternBad(vector<string> &username, vector<int> &timestamp, vector<string> &website) {
	unordered_map<string, int> combCount;
	unordered_map<string, vector<string>> userCount;
	vector<pair<int, string>> allComb;
	for(int i = 0; i < username.size(); i++) {
		userCount[username[i]].push_back(website[i]);
}

	for(auto it = userCount.begin(); it != userCount.end(); it++) {
		vector<string> websites = it->second;
		int numWeb = websites.size();
		for(int i = 0; i < numWeb; i++) {
			for(int j = i + 1; j < numWeb; j++) {
				for(int k = j + 1; k < numWeb; k++) {
					string comb = websites[i] + " " + websites[j] + " " + websites[k];
					combCount[comb]++;
				}
			}
		}
	}


	for(auto it = combCount.begin(); it != combCount.end(); it++) {
		allComb.push_back({it->second, it->first});
	}

	sort(allComb.begin(), allComb.end());

	return stringToArray(allComb[0].second);
}

int main() {
	vector<string> result;
    vector<string> username = {"alex","alex","alex","ken","ken","ken","ken","mary","mary","mary"};
    vector<int> timestamp = {1,2,3,4,5,6,7,8,9,10};
    vector<string> websites = {"lintcode","course","problem","lintcode","group","collection","lintcode","lintcode","course","problem"};
    result = mostVisitedPatternBad(username, timestamp, websites);
    for(int i = 0; i < result.size(); i++) {
    	cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}