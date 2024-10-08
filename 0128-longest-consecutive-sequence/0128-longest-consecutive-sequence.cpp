class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (!nums.size()) {
            return 0;
        }
        
        map<int, bool> mp; //  for faster finding the element
        for (auto i: nums) {
            mp[i] = true;
        }
        int cons = 0;
        int maxCons = 0;
        for (auto i: mp) {
             if (mp.count(i.first+1)) {
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