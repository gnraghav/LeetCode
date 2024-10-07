class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int i = 0;
        int j = 0;
        int res = INT_MAX;
        while (i<nums.size()) {
            sum += nums[i++];
            while (sum >= target) {
                res = min(res, i-j);
                sum -= nums[j++];
            }
        }
        return (res!=INT_MAX ? res : 0);
    }
};