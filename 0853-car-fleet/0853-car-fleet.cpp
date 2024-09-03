class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> data;// {pos, speed}
        for(int i=0;i<speed.size();i++) {
            data.push_back({position[i], speed[i]});
        }
        
        // sorting based on pos.
        sort(data.begin(), data.end());
        stack<double> st;
        for(auto i=data.rbegin();i!=data.rend();i++) {
            // finding the time.
            double dist = (target-i->first);
            double time = (double) dist/i->second; // (target-pos)/speed
            
            if(st.empty() || time > st.top()) {
                st.push(time);
            }
        }
        return st.size();
    }
};