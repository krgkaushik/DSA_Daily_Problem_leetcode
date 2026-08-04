class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int lowestNumber = INT_MAX;
        int highestNumber = INT_MIN;
        vector<int>ans;

        for( int i = 0 ; i<n; i++ ){
            lowestNumber = min( lowestNumber , nums[i] );
            highestNumber = max( highestNumber , nums[i] );
        }
        
        while( lowestNumber <= highestNumber ){
            bool present = false;
            for( int i = 0 ; i<n; i++ ){

                if( nums[i] == lowestNumber ){
                    present = true;
                }
                
            }
            if(!present){
                ans.push_back(lowestNumber);
            }
            lowestNumber++;
        }
        return ans;
    }
};