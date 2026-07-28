class Solution {
public:
    string smallestPalindrome(string s) {
        std::vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        std::string first_half = "";
        char middle_char = '\0';

        // Build the first half alphabetically
        for (int i = 0; i < 26; ++i) {
            // If the character has an odd count, save one for the middle
            if (count[i] % 2 != 0) {
                middle_char = 'a' + i;
            }
            // Put half of the occurrences into the first half
            first_half.append(count[i] / 2, 'a' + i);
        }

        // Create the second half by reversing the first half
        std::string second_half = first_half;
        std::reverse(second_half.begin(), second_half.end());

        // Combine the parts
        if (middle_char != '\0') {
            return first_half + middle_char + second_half;
        }
        return first_half + second_half;
    }
};