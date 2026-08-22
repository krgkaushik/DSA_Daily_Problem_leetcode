class Solution {
public:
    bool checkDivisibility(int n) {
        int check = n;
        int addition = 0 ;
        int multiplication = 1;

        while( n > 0 ){
            int curr = n%10;
            addition += curr;
            multiplication *= curr;
            n/=10;
        }
        
        int ans = addition + multiplication;
         return check % ans == 0;
        
    }
};