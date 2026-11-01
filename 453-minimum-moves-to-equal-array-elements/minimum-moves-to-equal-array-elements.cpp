class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums[0];
        long long curr = 0;
        for( int i = 0; i<nums.size(); i++ ){
            curr += nums[i] - n;
        }
        return curr;

    }
};