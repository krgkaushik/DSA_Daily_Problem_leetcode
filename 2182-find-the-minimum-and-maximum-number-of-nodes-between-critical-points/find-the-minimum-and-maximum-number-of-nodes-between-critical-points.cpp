/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        vector<int>v;
        while(head != nullptr ){
          v.push_back(head->val);
          head = head -> next;
        }

        vector<int>c;
        for( int i = 1 ; i < v.size()-1; i++ ){
            if( v[i-1] < v[i] && v[i] > v[i+1] || v[i-1] > v[i] && v[i] < v[i+1] ){
                c.push_back(i);
            }
        }

        if( c.size() < 2 ){
            return {-1,-1};
        }

        int minVal = INT_MAX;

        for( int i = 1; i<c.size(); i++ ){
            minVal = min( minVal , c[i] - c[i-1] );
        }
        
        int maxVal = c.back() - c.front();

        return {minVal , maxVal };
    }
};