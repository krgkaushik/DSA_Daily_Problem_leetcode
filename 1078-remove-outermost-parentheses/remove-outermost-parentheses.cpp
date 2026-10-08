class Solution {
public:
    string removeOuterParentheses(string s) {
        string res = "";
        int bal = 0 ;

        for( char ch : s ){
            if( ch == '(' ){
                if( bal > 0 ){
                    res += ch;
                }
                bal++;
            }
            else{
                bal--;
                if( bal > 0 ){
                    res += ch;
                }
            }
        }
        return res;
    }
};