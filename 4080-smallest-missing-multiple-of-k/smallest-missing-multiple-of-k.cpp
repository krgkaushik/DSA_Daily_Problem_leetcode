class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {

        set<int>map( nums.begin(), nums.end() );
        
        
        int i = 1;
        int ans;
        while( true ){
            int curr = i * k;
            if( !map.contains(curr) ){
                ans = curr;
                break;
            }
            i++;
        }
        
        return ans;
        
    }
};