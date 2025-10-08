class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int dataSize = temperatures.size();
        vector<int> daysToWait(dataSize, 0);
        stack<pair<int, int>> s;
        s.push({temperatures[0], 0});
        int day = 1;

        while(!s.empty() && day < dataSize) {
            while(!s.empty() && s.top().first < temperatures[day]) {
                int lowerTempDay = s.top().second;
                daysToWait[lowerTempDay] = day - lowerTempDay;
                s.pop();
            }

            if(!s.empty() && s.top().first >= temperatures[day]) {
                s.push({temperatures[day], day});
            }
            s.push({temperatures[day], day});
            day++;
        }
        
        while(!s.empty()) {
            daysToWait[s.top().second] = 0;
            s.pop();
        }

        return daysToWait;
    }
};