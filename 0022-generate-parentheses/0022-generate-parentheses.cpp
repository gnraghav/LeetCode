class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generateResString(res,"", n, 0);
        return res;
    }
    
    void generateResString(vector<string>&res, string str, int n, int m) {
        if (!n && !m) {
            res.push_back(str);
            return;
        }
        // for adding open bracket
        if (n > 0) generateResString(res, str+"(", n-1, m+1);
        // for adding close bracket
        if (m > 0) generateResString(res, str+")", n, m-1);
    }
    
};