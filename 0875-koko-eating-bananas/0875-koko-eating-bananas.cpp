class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
       // sort(piles.begin(),piles.end());
        int hours = 0;
       // int high = piles[piles.size()-1];
        int high = 1000000000; // considering some max value
        int res = INT_MAX;
        while(low<=high) {
            hours = 0;
            int mid = low+(high-low)/2;
            for (auto pile : piles) {
                hours += ceil(pile/ mid);
                if (pile%mid) hours++; // we have extra hour left
                if (hours > h) break;
            }
            if (hours <= h) {
                high = mid-1;
                res = min(res, mid);
            } else {
                low = mid+1;
            }
        }
        return res;
    }
};