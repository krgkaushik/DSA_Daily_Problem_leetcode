class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>v( n+1 , 0 );
        for( int i = 0 ; i<=n; i++ ){
            int count = 0;
            int k = i;
            while( k > 0 ){
                k &= (k-1);
                count++;
            }
            v[i] = count;
        }
        return v;
    }
};