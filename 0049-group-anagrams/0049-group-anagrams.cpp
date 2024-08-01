class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
            unordered_map<string, vector<string>> mp;
            vector<vector<string>> res;
            for(auto i: strs) {
                string s = i;
                sort(s.begin(), s.end());
                mp[s].push_back(i);
            }
            for(auto i: mp) {
                res.push_back(i.second);
            }   
            return res;
    }
};