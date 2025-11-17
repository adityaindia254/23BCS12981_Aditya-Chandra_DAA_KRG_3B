class Solution{
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity){
        ranges::sort(buses);
        ranges::sort(passengers);
        int j = 0, c = 0;
        for(auto bus: buses){
            c = capacity;
            while(c > 0 && j < passengers.size() && passengers[j] <= bus){
                c--;
                j++;
            }
        }
        int i = j-1; // last boarded passenger
        int ans = c>0? buses.back() : passengers[i];
        while(i >= 0 && ans == passengers[i]){
            i--;
            ans--;
        }
        return ans;
    }
};