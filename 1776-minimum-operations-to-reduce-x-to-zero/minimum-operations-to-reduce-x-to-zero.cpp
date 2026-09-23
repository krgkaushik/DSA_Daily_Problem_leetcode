class Solution {
public:
    int minOperations(vector<int>& nums, int x) {

        long long t = 0;

        for( int a : nums ){
            t += a;
        }

        int n = nums.size();
        int k = t - x;
        int l = -1;

        if( k == 0 ){
            return n;
        }

        int i = 0;
        int curr = 0 ;

        for( int j = 0 ; j<n; j++ ){
            curr += nums[j];

            while( curr > k && i <= j ){
                curr -= nums[i];
                i++;
            }

            if( curr == k ){
                l = max( l , j-i+1 );
            }
            

        }

        if( l == -1 ){
            return -1;
        }

 
        return n-l;
        
    }
};