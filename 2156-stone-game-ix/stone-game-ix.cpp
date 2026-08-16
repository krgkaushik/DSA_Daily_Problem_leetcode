class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int c0 = 0, c1 = 0, c2 = 0;
        
        // Count remainders
        for (int stone : stones) {
            int rem = stone % 3;
            if (rem == 0) c0++;
            else if (rem == 1) c1++;
            else c2++;
        }
        
        // Game theory conditions
        if (c0 % 2 == 0) {
            return c1 > 0 && c2 > 0;
        } else {
            return abs(c1 - c2) > 2;
        }
    }
};