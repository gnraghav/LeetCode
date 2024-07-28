class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // First sort all the given elements of nums vec.
        sort(nums.begin(),nums.end());
        // store the output of 3 Sum elements.
        vector<vector<int>> res;
        // Needed to keep track of non reprated vec 3 sum elements.
        set<vector<int>> setOut;        
        int target = 0; // Our target.
        
        // Using 2 pointers technique by keeping first element as fixed.
        for (int i=0;i<nums.size();i++) {
            int l = i+1;
            int r = nums.size()-1;
            
            // same as finding 2Sum.
            while (l<r) {
                int x = nums[i] + nums[l] + nums[r];
                if (x < target) {
                    l++;
                } else if (x > target) {
                    r--;
                } else {
                    setOut.insert({nums[i], nums[l], nums[r]});
                    l++; // Needed to forward
                    r--; // Needed to backward.
                }
            }
        }
        
        // Push output elements to res. (which is non repeated.)
        for (auto n:setOut) {
            res.push_back(n);
        }
        return res;
    }
};