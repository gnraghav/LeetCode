class Solution {
public:
    bool isPalindrome(string s) {
        string s1 = "";
        for(auto i: s) {
            if (isalnum(i)) {
                s1 += tolower(i);
            }
        }
        string s2 = s1;
        reverse(s1.begin(), s1.end());
        if (s1 == s2) {
            return true;
        }
        return false;
    }
};