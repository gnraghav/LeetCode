class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        int maxFreq = INT_MIN;
        vector<int> res;
        for (auto i: nums) {
             mp[i]++;
             maxFreq = max(maxFreq, mp[i]); // helps in bucket max storage.
        }
        // bucket[freq] = {values}
        vector<vector<int>> bucket(maxFreq+1);
        for (auto i: mp) {
            // same numbers can have same num of occurences 
            // num 1 -> freq 2
            // num 2 -> freq 2
            // num 3 -> freq 1
            // [2] -> {1, 2}
            // [1] -> {3}
            bucket[i.second].push_back(i.first);
        }
        
        for (int i=bucket.size()-1;i>0 && k>0;i--) { // freq
            for (int j=0;j<bucket[i].size() && k>0;j++) { // values
                res.push_back(bucket[i][j]);
                k--;
            }
        }

        return res;
    }
};