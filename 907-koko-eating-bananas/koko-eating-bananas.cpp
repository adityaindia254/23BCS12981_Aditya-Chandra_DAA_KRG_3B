class Solution {
public:
    int check(int mid, vector<int>& piles, int h) {
        long long val = 0;
        for (int j = 0; j < piles.size(); j++) {
            val += piles[j] / mid;
            if (piles[j] % mid != 0) {
                val++;
            }
        }
        return val <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        long long l = 1, r = 1e9, ans = -1 ;
        while (l <= r) {
            int mid = (l + r) / 2 ;
            if (check(mid, piles, h)) { 
                ans = mid ; 
                r = mid - 1; }
            else {
                l = mid + 1;
            }
        }
        return ans ;  
    }
};