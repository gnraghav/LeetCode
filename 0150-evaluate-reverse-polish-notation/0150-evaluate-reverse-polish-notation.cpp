class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (auto i: tokens) {
            if ((i!="+") && (i!="-") && (i!="/") && (i!="*"))  {
                st.push(stoi(i));
            } else if (st.size() >= 2){
                int d1 = st.top();
                st.pop();
                int d2 = st.top();
                st.pop();
                if (i == "+") {
                   st.push(d1+d2);
                } else if (i == "-") {
                   st.push(d2-d1);
                }  else if (i == "*") {
                   st.push(d1*d2);
                }  else if (i == "/") {
                   st.push(d2/d1);
                } 
            } else {
                return st.top();
            }
        }
        return st.top();;
    }
};