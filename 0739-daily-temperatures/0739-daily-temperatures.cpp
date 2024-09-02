class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0); // to return the res
        stack<pair<int,int>> st; // to store the last greater element
        
        // traverse from back since we get the large temp in the end of list.
        for(int i = n-1;i>=0;i--) {
            int curr = temperatures[i];
            while(!st.empty() && st.top().first <= curr) st.pop();
            
            res[i] = (st.empty() ? 0 : st.top().second-i);
            st.push({curr, i});
        }
        return res;
    }
};