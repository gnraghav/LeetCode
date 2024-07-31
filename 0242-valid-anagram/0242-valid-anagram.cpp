class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        
        map<char, int> mp;
        for (auto i : s) {
             mp[i]++;
        }
        for (auto i: t) {
            if (mp.find(i) == mp.end() || !mp[i]) {     
                return false;
            }
            mp[i]--;
        }
        return true;
    }
};