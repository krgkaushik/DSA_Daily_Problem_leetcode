class Solution {
public:
    bool checkString(string s) {
        
        int n = s.length();
        
        bool a = false;

        for( int i = 0 ; i<n; i++ ){
            if( a && s[i] == 'a' ){
                return false;
            }
            if( s[i] == 'b' ){
                a = true;
            }
        }

        return true;
    }
};