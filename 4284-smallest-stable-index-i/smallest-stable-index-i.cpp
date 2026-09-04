class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {

        for( int i = 0 ;i<nums.size(); i++ ){
            int maxVal = *max_element(nums.begin() , nums.begin() + i );
            int minVal = *min_element(nums.begin()+i , nums.end());
   
            int ans  = maxVal - minVal;

            if( ans <= k ){
                return i;
            }
        }

        return -1;
        
    }
};