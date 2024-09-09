class Solution {
public:
int divide(int dividend, int divisor) {
    if (divisor == 0) {
        printf("Error: Division by zero\n");
        exit(EXIT_FAILURE);
    }

    int quotient = 0;
    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

    dividend = abs(dividend);
    divisor = abs(divisor);

    while (dividend >= divisor) {
        dividend -= divisor;
        quotient++;
    }

    return sign * quotient;
}

    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        
        while(low<=high) {
            int mid = divide((low+high), (1<<1));
            if (nums[mid] == target) {
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