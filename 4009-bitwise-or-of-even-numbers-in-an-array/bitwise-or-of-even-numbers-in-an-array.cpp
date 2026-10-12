class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {

        int ans = 0;
        for( int i = 0 ; i < nums.size(); i++ ){
            int n = nums[i];
            if( !(n & 1) ){
              ans |= n;  
            }
        }
        return ans;
        
    }
};