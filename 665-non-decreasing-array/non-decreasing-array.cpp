class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        
        int n = nums.size();

        if( n == 1 || n == 2 ){
            return true;
        }
        bool c = false;
        for( int i = 1; i<n; i++ ){
            if( nums[i-1] > nums[i] ){
                if( i == n-1 ){
                    nums[i] = nums[i-1];
                    break;
                }
                if(i == n-1 || nums[i+1] <= nums[i-1] ){
                    nums[i-1] = nums[i];
                 
                    break;
                }
                else{
                    nums[i] = nums[i-1];
                
                    break;
                }
            }
        }


        for( int i= 1 ; i<n; i++ ){
            if( nums[i-1] > nums[i] ){
                return false;
            }
        }

        return true;
    }
};