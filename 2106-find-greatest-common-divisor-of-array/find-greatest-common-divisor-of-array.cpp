class Solution {
public:

   
    int findGCD(vector<int>& nums) {
        int s = INT_MAX;
        int l = INT_MIN;
        int gcd = 1;

        for( int i = 0 ; i<nums.size(); i++ ){
            s = min( s ,  nums[i] );
            l = max( l , nums[i] );
        }

        while( s > 0 ){
            int temp = s;
            s = l%s;
            l = temp;
        }

        return l ;

                
    }
};