class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {

        unordered_map<string , string>d;
        for( int i = 0 ; i<knowledge.size(); i++ ){
            d[knowledge[i][0]] = knowledge[i][1];
        }
        string res = "";

        for( int i = 0; i<s.size(); i++ ){
            if( s[i] == '(' ){
                int j = s.find(")" , i+1 );
                auto t = s.substr( i +1 , j-i-1 );
                if(d.count(t)){
                    res += d[t];
                }
                else{
                    res += "?";
                }
                i = j;
            }
            else{
                res += s[i];
            }
        }

        return res;
        
    }
};