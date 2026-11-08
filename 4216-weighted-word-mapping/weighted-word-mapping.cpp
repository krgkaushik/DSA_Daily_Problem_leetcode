class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int n = words.size();  
        string ans = "";

        for( int i = 0 ; i<words.size(); i++ ){
            string curr = words[i];
            int sum = 0;
            for( char ch : curr ){
               sum += weights[ch-'a'];
            }
            int mod = sum%26;
            ans += 'z' - mod;
        }
        return ans;
    }
};