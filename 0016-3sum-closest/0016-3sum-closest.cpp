class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() < 3) return 0;
        // assuming this as closeset,
        int res = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for (int i=0;i<nums.size();i++) {
            if (i>0 && nums[i] == nums[i-1]) continue; // lets not process the same element
            int l = i+1;
            int r = nums.size()-1;
            while (l<r) {
                int nSum = nums[i] + nums[l] + nums[r];
                // direct Ans target found
                if (nSum == target) { 
                    res = nSum;
                    return res;
                }      
                // store the closest value as res.
                if (abs(nSum-target) < abs(res-target)){
                   res = nSum;
                }           
                
                // move the pointers front and back.
                if (nSum > target) {
                    r--;
                } else if (nSum < target) {
                    l++;
                }
            }
        }
        return res;
    }
};