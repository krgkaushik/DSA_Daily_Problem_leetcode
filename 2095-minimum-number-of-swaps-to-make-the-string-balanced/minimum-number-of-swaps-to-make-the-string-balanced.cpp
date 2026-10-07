class Solution {
public:
    int minSwaps(string s) {
        
        int balance = 0;
        int minBalance = 0;
        for( char ch : s ){
            if( ch == '[' ){
                balance++;
            }
            else{
                balance--;
            }
            minBalance = min( minBalance , balance );
        }
        return (abs(minBalance)+1)/2;
    }
};