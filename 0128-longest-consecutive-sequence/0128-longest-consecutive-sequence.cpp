class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (!nums.size()) {
            return 0;
        }
        
        set<int> s;
        map<int, bool> mp;
        vector<int> n;
        for (auto i: nums) {
            s.insert(i);
            mp[i] = true;
        }
        int cons = 0;
        int maxCons = 0;
        for (auto i: s) {
             if (mp.count(i) && mp.count(i+1)) {
                 cons += 1;
             } else {
                 maxCons = max(maxCons, cons+1);
                 cons = 0;
             }
        }
        maxCons = max(maxCons, cons);
        return maxCons;
    }
};