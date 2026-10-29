class Solution {
public:
    int strStr(string haystack, string needle) {
        int a = 0;
        int j = needle.size();
        for( int i = 0 ; i<haystack.size(); i++ ){
           if( haystack[i] == needle[0] ){
            string curr = haystack.substr( i , j );
            if( curr == needle ){
                return i;
            }
           }
        }

        return -1;
        
    }
};