class Solution {
public:
    int minMoves(vector<int>& nums) {

        int n = nums.size();
        sort(nums.begin(),nums.end());
        int maxNum = nums[n-1];
        int sum = 0;
        for( int x : nums ){
            sum += maxNum - x;
        }
        return sum;
        
    }
};