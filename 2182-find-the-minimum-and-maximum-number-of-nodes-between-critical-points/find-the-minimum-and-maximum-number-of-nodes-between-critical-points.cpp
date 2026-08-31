class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        vector<int> v;

        // Step 1: Linked List -> Vector
        while (head != nullptr) {
            v.push_back(head->val);
            head = head->next;
        }

        vector<int> critical;

        // Step 2: Find critical points
        for (int i = 1; i < v.size() - 1; i++) {

            // Local maximum OR local minimum
            if ((v[i] > v[i-1] && v[i] > v[i+1]) ||
                (v[i] < v[i-1] && v[i] < v[i+1])) {

                critical.push_back(i);
            }
        }

        // Step 3: Fewer than 2 critical points
        if (critical.size() < 2) {
            return {-1, -1};
        }

        // Step 4: Find minimum distance
        int minDist = INT_MAX;

        for (int i = 1; i < critical.size(); i++) {
            minDist = min(minDist,
                          critical[i] - critical[i-1]);
        }

        // Step 5: Maximum distance
        int maxDist = critical.back() - critical.front();

        return {minDist, maxDist};
    }
};