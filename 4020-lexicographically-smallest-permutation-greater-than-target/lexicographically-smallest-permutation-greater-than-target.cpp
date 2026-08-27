class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
         vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        string ans = "";

        for (int i = 0; i < target.size(); i++) {
            int x = target[i] - 'a';

            // We can keep the answer equal to target so far
            if (freq[x] > 0) {
                ans += target[i];
                freq[x]--;
                continue;
            }

            // Cannot use target[i].
            // Try to make the answer greater at this position.
            for (int j = x + 1; j < 26; j++) {
                if (freq[j] > 0) {
                    ans += char('a' + j);
                    freq[j]--;

                    // Add all remaining characters in sorted order
                    for (int k = 0; k < 26; k++) {
                        while (freq[k] > 0) {
                            ans += char('a' + k);
                            freq[k]--;
                        }
                    }

                    return ans;
                }
            }

            // No greater character here.
            // We need to backtrack.
            break;
        }

        // Backtrack through previously matched characters
        for (int i = ans.size() - 1; i >= 0; i--) {

            // Put ans[i] back into frequency
            freq[ans[i] - 'a']++;

            int x = target[i] - 'a';

            // Find the smallest character > target[i]
            for (int j = x + 1; j < 26; j++) {
                if (freq[j] > 0) {

                    string result = ans.substr(0, i);

                    result += char('a' + j);
                    freq[j]--;

                    // Remaining characters in sorted order
                    for (int k = 0; k < 26; k++) {
                        while (freq[k] > 0) {
                            result += char('a' + k);
                            freq[k]--;
                        }
                    }

                    return result;
                }
            }
        }

        return "";
        
    }
};