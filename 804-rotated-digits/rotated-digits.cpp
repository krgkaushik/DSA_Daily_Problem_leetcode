class Solution {
public:
    int rotatedDigits(int n) {
        
        int cnt = 0;
         

        for( int i = 1 ; i<=n ; i++ ){
        bool isValid = true;
        bool haschange = false;
            
           int num = i;
           while( 0 < num ){
           int digit = num % 10;
           
           if( digit == 3 || digit == 4 || digit == 7 ){
            isValid = false;
            break;
           }

           if( digit == 2 || digit == 5 || digit == 6 || digit == 9 ){
            haschange = true;
           }
           num/=10;
           }
           if( isValid && haschange ){
            cnt++;
           }
            
        }

        return cnt;
    }
};