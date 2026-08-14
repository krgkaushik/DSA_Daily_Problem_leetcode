class Solution:
    def maximumLengthSubstring(self, s: str) -> int:
        count = [0] * 26
        left = 0
        max_len = 0
        
        for right in range(len(s)):
            idx = ord(s[right]) - ord('a')
            count[idx] += 1
            
            while count[idx] > 2:
                left_idx = ord(s[left]) - ord('a')
                count[left_idx] -= 1
                left += 1
                
            max_len = max(max_len, right - left + 1)
            
        return max_len