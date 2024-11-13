class Solution {
public:
    int climbStairs(int n) {
         if (n==1 || n==2) {
             return n;
         }
         vector<int> fib(n);
         fib[0] = 1;
         fib[1] = 2;
         for (int i = 2;i<n;i++) {
             fib[i] = fib[i-1]+fib[i-2];
         }
        
         return fib[n-1];
    }
};