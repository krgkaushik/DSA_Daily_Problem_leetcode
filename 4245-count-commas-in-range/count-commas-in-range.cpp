class Solution {
public:
    int countCommas(int n) {

        if( n < 1000 ){
            return 0;
        }

        int i = n - 1000;
        i++;
        return i;
        
    }
};