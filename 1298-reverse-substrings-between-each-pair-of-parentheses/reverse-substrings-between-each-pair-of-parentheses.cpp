class Solution {
public:
    string reverseParentheses(string s) {

        while( s.find(')') != string::npos ){
            int r = s.find(')');
            int l = r - 1;

            while( s[l] != '(' ){
                l--;
            }

            reverse(s.begin()+l+1 , s.begin()+r );

            s.erase(r , 1);
            s.erase(l , 1);
        }
        return s;
    }
};