class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>pSum;
        int res = 0;
        int sum = 0;
      //  pSum[0] = 1;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            res +=(sum ==k ? 1 :0);
            if (pSum.count(sum-k)) {
                res +=pSum[sum-k];
            }
            pSum[sum]++;
        }
        
        return res;
    }
};