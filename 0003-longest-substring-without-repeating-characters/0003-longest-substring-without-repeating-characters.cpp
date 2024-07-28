class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> seen(256, -1); // max char ascii
        int len = s.size();
        int maxC = 0;
        int start = -1;
        for (int i=0;i<len;i++) {
            if (seen[s[i]] > start) {
               start = seen[s[i]];
            }
            seen[s[i]] = i;
            maxC = max(maxC, i-start);
        }
        return maxC;
    }
};