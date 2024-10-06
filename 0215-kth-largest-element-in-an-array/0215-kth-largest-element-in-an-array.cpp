class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // set<int> s1(nums.begin(), nums.end());
        // for (auto i=s1.rbegin();i!=s1.rend();i++) {
        //     k--;
        //     if (!k) return *i;
        // }
        // return 0;
        
        // find large and small element in a vector
        int low=INT_MAX, high=INT_MIN;
        for (auto i: nums) {
            low = min(low, i);
            high = max(high, i);
        }
        
        while (low<=high) {
            int mid = low+(high-low)/2;
            int count =0;
            for(auto i: nums) {
                if (i >= mid) {
                    count++;
                }
            }
            if (count >= k) {
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        set<int> s;
        for (auto i : nums) {
            if ( i >= high) {
                s.insert(i);
            }
        }
        auto i=s.begin();
        return *i;
    }
};