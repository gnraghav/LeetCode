class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size()-1;
        while (l < r) {
            if (numbers[l] + numbers[r] == target) {
                return {l+1, r+1};
            }
            l += (numbers[l]+numbers[r] < target ? 1 : 0);
            r -= (numbers[l]+numbers[r] > target ? 1 : 0);
        }
        return {};
    }
};