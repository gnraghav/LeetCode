class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            sum = nums[i];
            count += ((sum == k) ? 1 : 0);
            for(int j = i + 1; j < nums.size(); j++)
            {
                sum += nums[j];
                count += ((sum == k) ? 1 : 0);
            }   
        }
        return count;
    }
};