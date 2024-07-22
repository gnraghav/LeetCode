class NumArray {
public:
// nums: [-2, 0, 3, -5, 2, -1]
// pSum: [-2, -2, 1, -4, -2, -3]
    vector<int> pSum;
    int sum{0};  
    NumArray(vector<int>& nums) {      
        for(auto i:nums) {
            sum += i;
            pSum.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        return (left ? pSum[right]-pSum[left-1] : pSum[right]);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */