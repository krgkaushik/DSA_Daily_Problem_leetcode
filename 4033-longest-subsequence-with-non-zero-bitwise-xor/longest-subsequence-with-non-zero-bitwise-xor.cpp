class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int total_xor = 0;
        bool has_zero = false;

        for( int num : nums ){
            total_xor ^= num;
            if( num != 0 ){
                has_zero = true;
            }
        }

        if( !has_zero ){
            return 0;
        }
        
        if( total_xor != 0 ){
            return nums.size();
        }

        return nums.size() - 1;
    }
};