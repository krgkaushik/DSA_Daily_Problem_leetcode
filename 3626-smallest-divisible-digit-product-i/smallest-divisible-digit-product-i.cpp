class Solution {
public:
    int smallestNumber(int n, int t) {
        int curr = n;
        while (true) {
            int prod = 1;
            int temp = curr;
            
            // Calculate product of digits
            while (temp > 0) {
                prod *= (temp % 10);
                temp /= 10;
            }
            
            // Check divisibility
            if (prod % t == 0) {
                return curr;
            }
            
            curr++;
        }
    }
};