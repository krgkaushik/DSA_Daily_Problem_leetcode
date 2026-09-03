class Solution {
public:
    bool uniformArray(vector<int>& nums1) {

        int val = *min_element(nums1.begin() , nums1.end() );

        if( val % 2 == 1 ){
            return true;
        }
        
        for( int x : nums1 ){
            if( x%2 == 1 ){
                return false;
            }
        }

        return true;
    }
};