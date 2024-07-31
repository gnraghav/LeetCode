class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
            map<int,int> mp;
            int x;
            for (int i=0;i< nums.size();i++) {
                x = target - nums[i];
                if (mp.count(x)) {
                    return {mp[x],i};
                }
                mp[nums[i]] = i;
            }
          return {-1, -1};
        }
};