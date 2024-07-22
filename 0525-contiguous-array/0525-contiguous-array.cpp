class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int,int> mp;
        int sum = 0;
        mp[0] = -1;
        int res =0;
        for (auto i=0;i<nums.size();i++) {
             sum += (nums[i] ? 1 : -1);
            if (mp.count(sum)) {
                res = max(res, i-mp[sum]);
            } else {
                mp[sum] = i;
            }
        }
        return res;
    }
};