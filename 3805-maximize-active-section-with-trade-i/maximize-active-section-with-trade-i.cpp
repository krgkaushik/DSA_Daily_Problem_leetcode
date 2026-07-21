#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        // Count base active sections in the original string
        int base_1s = 0;
        for (char c : s) {
            if (c == '1') base_1s++;
        }
        
        // Form augmented string to guarantee boundaries
        string t = "1" + s + "1";
        
        vector<int> O; // Lengths of '1' blocks
        vector<int> Z; // Lengths of '0' blocks
        
        int count = 1;
        char current = t[0];
        
        // Parse the alternating blocks of '1's and '0's
        for (int i = 1; i < t.length(); i++) {
            if (t[i] == current) {
                count++;
            } else {
                if (current == '1') O.push_back(count);
                else Z.push_back(count);
                current = t[i];
                count = 1;
            }
        }
        
        // Push the final block of '1's
        if (current == '1') O.push_back(count);
        
        int k = Z.size();
        
        // If there are fewer than 2 '0' blocks, there are no '1' blocks 
        // surrounded by '0's. A valid trade is impossible.
        if (k < 2) return base_1s;
        
        // Precompute prefix and suffix maximums of '0' blocks
        vector<int> pref(k, 0);
        vector<int> suff(k, 0);
        
        pref[0] = Z[0];
        for (int i = 1; i < k; i++) pref[i] = max(pref[i-1], Z[i]);
        
        suff[k-1] = Z[k-1];
        for (int i = k - 2; i >= 0; i--) suff[i] = max(suff[i+1], Z[i]);
        
        int max_gain = 0;
        
        // Iterate through all internal '1' blocks (O[1] to O[k-1])
        for (int i = 1; i < k; i++) {
            // Choice 1: Fill the newly merged '0' block
            int gain_combined = Z[i-1] + Z[i];
            
            // Choice 2: Fill the largest alternative '0' block
            int max_other_Z = 0;
            if (i >= 2) max_other_Z = max(max_other_Z, pref[i-2]);
            if (i <= k - 2) max_other_Z = max(max_other_Z, suff[i+1]);
            
            int gain_other = max_other_Z - O[i];
            
            // Record maximum overall gain
            max_gain = max({max_gain, gain_combined, gain_other});
        }
        
        return base_1s + max_gain;
    }
};