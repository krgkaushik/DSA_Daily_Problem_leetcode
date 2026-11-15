class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0;
        int curr = 0;
        for( int x : gain ){
            curr += x;
            ans = max( curr , ans ); 
        }
        return ans;
    }
};