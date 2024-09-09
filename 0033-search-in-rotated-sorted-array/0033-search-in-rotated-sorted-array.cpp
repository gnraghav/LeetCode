class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        int mid ;            

        // find the starting element in a sorted array.
        // below loop will exit when it finds the first small element
        while(low<high) {
            mid = (low+high)/2;
            if (nums[mid] > nums[high]) {
                low = mid+1;
            } else {
                high = mid; 
            }
        }
        
        int s = low;
        low = 0;
        high = nums.size()-1;
        if (target >= nums[s] && target <=nums[high]) {
            low = s;
        } else {
            high = s;
        }
        
        while(low<=high) {
            mid = (low+high)/2;
            if (target == nums[mid]) {
                return mid;
            } 
            if (target < nums[mid]) {
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return -1;
    }
};