class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {

        int n = nums.size();
        unordered_set<int>s(nums.begin() , nums.end());
        for( int i = 1; i<n+1; i++ ){
            if( s.find(i) == s.end() ){
                return i;
            }
        }
        return n+1;
    }
};