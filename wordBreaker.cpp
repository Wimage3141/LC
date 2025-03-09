class Solution {
// something
public:
    unordered_map<int, bool> dp;

    bool wordBreak(string s, vector<string>& wordDict) {
        dp[s.size()] = true;
        return wordBreakHelper(s, wordDict, 0);
    }
private:
    bool wordBreakHelper(string s, vector<string>& wordDict, int i) {
        if(i == s.size()) return true;

        if(dp.find(i) != dp.end()) return dp[i];

        for(const string& word : wordDict) {
            if (i + word.size() <= s.size() &&
                s.substr(i, word.size()) == word &&
                wordBreakHelper(s, wordDict, i + word.size())) {
                    dp[i] = true;
                    return true;
                }
        }
        dp[i] = false;
        return false;
    }
};
