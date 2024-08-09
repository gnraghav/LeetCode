class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        unordered_map<char, int> mp;
        for (char c : s1) {
            mp[c]++;
        }

        int left = 0, right = 0, count = s1.size();

        while (right < s2.size()) {
            if (mp[s2[right]] > 0) {
                count--;
            }
            mp[s2[right]]--;
            right++;

            if (count == 0) return true;

            if (right - left == s1.size()) {
                if (mp[s2[left]] >= 0) {
                    count++;
                }
                mp[s2[left]]++;
                left++;
            }
        }

        return false;
    }
};