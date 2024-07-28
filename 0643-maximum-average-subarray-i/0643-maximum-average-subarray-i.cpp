class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double avg = INT_MIN;
        double sum = 0;
        for (int i=0;i<nums.size();i++) {
            if (i < k) {
                sum +=nums[i];
            } else {
                avg = (avg > sum/k ? avg : sum/k);
                sum += nums[i] - nums[i-k]; // in total sum subtract first element val.
            }
        }
        // this is needed to handle single element in given list.
        avg = (avg > sum/k ? avg : sum/k);
        return avg;
    }
};