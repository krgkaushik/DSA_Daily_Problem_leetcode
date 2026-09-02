class Solution {
public:
    bool uniformArray(vector<int>& nums1) {

        vector<int>v(nums1.size() , 0 );
        for( int i =0 ; i<nums1.size(); i++ ){
            for( int j = 0; j<nums1.size(); j++ ){
                if( i == j ){
                    continue;
                }
                if( nums1[i]%2==0 ){
                   v[i] = nums1[i];
                   break;
                }
                int curr = nums1[i] - nums1[j];

                if( curr%2 == 0 ){
                    v[i] = curr;
                    break;
                }
            }
        }
        for( int i = 0 ; i<v.size(); i++ ){
            cout<<v[i]<<" ";
            if( v[i]%2 != 0 ){
                return false;
            }
        }

        return true;
        
    }
};