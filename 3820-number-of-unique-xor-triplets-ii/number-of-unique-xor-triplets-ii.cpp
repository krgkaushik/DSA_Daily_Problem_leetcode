class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {

        int n = nums.size();
        unordered_set<int>ones;
        unordered_set<int>twos;
        unordered_set<int>three;

        for( int x : nums ){
            ones.insert(x);

        }
        for( int x : nums ){
            for( int y : ones ){
                twos.insert(x ^ y );
            }
        }

        for( int x : nums ){
            for( int y : twos ){
                three.insert( x ^ y );
            }
        }
        return three.size();
        
    }
};