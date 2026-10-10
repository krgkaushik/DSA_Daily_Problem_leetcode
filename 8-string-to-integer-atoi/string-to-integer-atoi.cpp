class Solution {
public:
    int myAtoi(string s) {
        int sign = 1;
        int i = 0 ;
        int n = s.size();
        long long num = 0;
        while( i < n && s[i] == ' ' ){
            i++;
        }
        if( i < n && s[i] == '+' || s[i] == '-' ){
            if( s[i] == '-' ){
                sign = -1;
            }
            i++;
        }
        while( i<n && s[i] >= '0' && s[i] <= '9' ){
            int digit = s[i] - '0';
            num = num * 10 + digit;

            if( sign  == 1 && num  > INT_MAX ){
                return INT_MAX;
            }

            if( sign == -1 && -num < INT_MIN ){
                return INT_MIN;
            }
            i++;
        }
        return num*sign;
        
    }
};