class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> vc(26,0); // total 26 char a-z
        int low = 0;
        int maxResLen = 0;
        int maxCharOccur = 0;
        for (int i=0;i<s.size();i++) {
            vc[s[i]-'A']++; // frequency tracking
            maxCharOccur = max(maxCharOccur, vc[s[i]-'A']); // keep max char occurance count
            // to check how many characters we can keep based on k.
            // i-low+1 is window size (total len of characters processed till now)
            // - maxCharOccur will give the specific num charctes
            while (i-low+1-maxCharOccur > k) { 
                 vc[s[low]-'A']--; // decrement the count
                 low++; // moving to next char
            }
            maxResLen = max(maxResLen, i-low+1);
        }
        return maxResLen;
    }
};