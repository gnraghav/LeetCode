class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> seen(256, -1); // max char ascii 0-127
        int len = s.size();
        int maxC = 0;
        int start = -1;
        for (int i=0;i<len;i++) {
            if (seen[s[i]] > start) {  // if entry present means repeated. 
               start = seen[s[i]];
            }
            // update the latest pair values. means, string with its index.
            seen[s[i]] = i;
            maxC = max(maxC, i-start);
        }
        return maxC;
    }
};