#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
    // Helper function to calculate the number of distinct permutations 
    // of a multiset given the character counts.
    long long calc_ways(const vector<int>& count, long long limit) {
        long long ways = 1;
        int n = 0;
        for (int c = 0; c < 26; ++c) {
            for (int i = 1; i <= count[c]; ++i) {
                n++;
                ways = (ways * n) / i;
                if (ways > limit) {
                    return limit + 1; // Cap to avoid integer overflow
                }
            }
        }
        return ways;
    }

public:
    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        vector<int> count(26, 0);
        string mid = "";
        int n = 0;
        
        for (int i = 0; i < 26; ++i) {
            if (freq[i] % 2 != 0) {
                mid += (char)(i + 'a');
            }
            count[i] = freq[i] / 2;
            n += count[i];
        }

        // Verify if k is within the boundary of total possible combinations
        long long total_ways = calc_ways(count, k);
        if (total_ways < k) {
            return "";
        }

        string half = "";
        for (int i = 0; i < n; ++i) {
            for (int c = 0; c < 26; ++c) {
                if (count[c] > 0) {
                    count[c]--; // Temporarily place character c
                    
                    long long ways = calc_ways(count, k);
                    if (ways < k) {
                        k -= ways;      // Not in this block, skip
                        count[c]++;     // Backtrack
                    } else {
                        half += (char)(c + 'a'); // Lock in character c
                        break;
                    }
                }
            }
        }

        string rev_half = half;
        reverse(rev_half.begin(), rev_half.end());

        return half + mid + rev_half;
    }
};