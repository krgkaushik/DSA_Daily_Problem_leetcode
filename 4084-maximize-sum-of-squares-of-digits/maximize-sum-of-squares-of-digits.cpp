class Solution {
public:
    string maxSumOfSquares(int num, int sum) {

        if( num*9 < sum ){
            return "";
        }

        string ans = "";

        while( num > 0 ){
            int digit = min( 9 , sum );
            ans += char('0'+digit );
            sum -= digit;
            num--;

        }

        if( ans == "" ){
            return "";
        }
        return ans ;
        
    }
};