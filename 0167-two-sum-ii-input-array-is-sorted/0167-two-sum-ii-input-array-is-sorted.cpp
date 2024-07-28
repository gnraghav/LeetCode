class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int>mp;
        int x = 0;
        for(int i=0;i<numbers.size();i++) {
            mp[numbers[i]] = i;
        }
        for(int i=0;i<numbers.size();i++) {
            x = target-numbers[i];
            if (mp.count(x)) {
                return {i+1, mp[x]+1};
            }
        }
        return {-1, -1};
    }
};