class Solution {
public:
    bool isValid( string s ){
        if(s.empty()){
            return true;
        }
        int b = 0;
        for( int i = 0 ; i<s.size(); i++ ){
            if( s[i] == '(' ){
                b++;
            }
            else if (s[i] == ')') {
                    b--;
                    if (b < 0)
                        return false;
                }
        }

        if( b == 0 ){
            return true;
        }
        return false;
    }
    void solve( int k , int index , string s, set<string>&ans ){
        if( k == 0 ){
            if(isValid(s)){
                ans.insert(s);
            }
            return;
        }
        for( int i = index ; i<s.size(); i++ ){
              if (s[i] != '(' && s[i] != ')')
            continue;

        string next = s.substr(0, i) + s.substr(i + 1);

        solve(k-1, i ,next , ans);
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        set<string>ans;

        int k = 0 ;
        
        int left = 0 ;
        int right = 0;
        for( int i = 0 ; i<s.size(); i++ ){
           if (s[i] == '(') {
                    left++;
                }
                else if (s[i] == ')') {
                    if (left > 0) {
                        left--;
                    }
                    else {
                        right++;
                    }
                }
        }
        k = left + right;
        solve( k , 0 , s , ans );
        vector<string>l(ans.begin() , ans.end());
        return l;

        
    }
};