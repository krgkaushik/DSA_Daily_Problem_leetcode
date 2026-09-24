class Solution {
public:
    int smallestIndex(vector<int>& nums) {

        for( int i = 0 ; i<nums.size(); i++ ){
            int sum = 0 ;
            int s = nums[i];


            while(s > 0) {
                sum += s % 10;
                s /= 10;
            }

            if(sum == i) {
                return i;
            }
        }
        return -1;
    }
};