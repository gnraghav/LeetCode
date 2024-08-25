class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for (auto i: s) {
             if ((i == '(') ||
                 (i == '{') ||
                 (i == '[')) {
                 st.push(i);
             } else {
                if (st.empty()) {
                    return false;
                }
                char t = st.top();
                if ((t == '(' && i == ')') ||
                    (t == '[' && i == ']') ||
                    (t == '{' && i == '}')) {
                    st.pop();
                    continue;
                }
                 return false;
             }
        }
        if (!st.empty()) {
            return false;
        }
        return true;
    }
};