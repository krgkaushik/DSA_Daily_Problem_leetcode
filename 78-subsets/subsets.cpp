class Solution {
public:
    void ans( set<vector<int>>&s , int i , vector<int>v , int n , vector<int> nums ){
         
         if( i == n ){
            s.insert(v);
            return;
         }
         v.push_back(nums[i]);
         ans( s , i+1 , v , n , nums );
         v.pop_back();
         ans(s, i + 1, v, n , nums );

       
    }
    vector<vector<int>> subsets(vector<int>& nums) {

        set<vector<int>>s;
        int n  = nums.size();
        for( int i = 0 ; i<nums.size(); i++ ){
            vector<int>v;
            ans(s , i , v , n , nums );
        }
        vector<vector<int>>ans1(s.begin() , s.end());
        return ans1;
    }
};