class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 1);
        for (int i=1;i<nums.size();i++) {
            ans[i] = ans[i-1] * nums[i-1]; // by keeping first index 1, keep track of product prefix.
        }
        
        int right = 1;
        for (int i=nums.size()-1;i>=0;i--) {
            ans[i] = ans[i] * right; // prefix * suffix
            right *= nums[i];
        }

        return ans;
    }
};