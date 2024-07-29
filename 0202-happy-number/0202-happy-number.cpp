class Solution {
public:
    // Cycle means, we need to try applying fast & slow pointer approach. 
    // Find the sum of square of num.
    int
    getSumSquareNum(int n) {
        int sum = 0;
        while (n) {
            int n1 = n%10;
            sum += n1 * n1;
            n = n/10;
        }
        return sum;
    }
    
    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        do {
            slow = getSumSquareNum(slow);
            fast = getSumSquareNum(fast);
            fast = getSumSquareNum(fast);   
        } while (slow != fast);
        
        if (slow == 1) {
            return true;
        }
        return false;
    }
};