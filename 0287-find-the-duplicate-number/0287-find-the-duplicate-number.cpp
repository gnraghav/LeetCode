class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // int64_t n =0; // keeps tracks of bit of each numbers.
        // for (int i : nums) {
        //     // if (n & (1<<i)) {
        //     //     return i; // repeated
        //     // }
        //     // n |= (1<<i); // mark the num in that bit.
        // }
        // return -1;
        int slow = 0;
        int fast = 0;
        // we know that dup is present. like loop.
        do {
            slow = nums[slow];
            fast = nums[fast];
            fast = nums[fast];            
        } while (slow != fast);
        
        fast = 0; // reset
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast]; 
        } 
        return fast;
    }
};