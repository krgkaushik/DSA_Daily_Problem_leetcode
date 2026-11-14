class Solution {
public:
    int check( vector<int>v ){
        int a = 0;
        for( int x : v ) a += x;
        return a;
    }
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        
        int ans = INT_MAX;
        int n = nums.size();
        for( int i = 0 ; i<n; i++ ){
            vector<int>v;
            for( int j = i; j<n; j++ ){
             v.push_back(nums[j]);
             if( v.size() >= l && v.size() <= r ){
                int curr = check(v);
                if( curr > 0 ){
                ans = min(curr,ans);
                     
                } 
             }
            }
        }
        if( ans == INT_MAX ){
            return -1;
        }
        return ans;

    }
};