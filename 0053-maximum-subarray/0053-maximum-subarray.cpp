class Solution {
public:
    int maxSubArray(vector<int>& nums) {
         int sum = nums[0];
         int cSum = 0;
         for (int i=0;i<nums.size();i++) {
              if (cSum < 0) {
                  cSum = 0;
              }
              cSum += nums[i];
              sum = max(sum, cSum);
         }
         return sum;
    }
};