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
    ListNode* deleteDuplicates(ListNode* head) {
        vector<int>v;
        ListNode*temp = head;
        while( temp != nullptr ){
            v.push_back(temp->val);
            temp = temp -> next;
        }
        unordered_map<int,int>mp;

        for( int k : v ){
            mp[k]++;
        }

        ListNode*ans = new ListNode(9);

        temp = ans;

        for( int i = 0 ; i<v.size(); i++ ){
            if( mp[v[i]] == 1 ){
                ListNode*newN = new ListNode(v[i]);
                temp -> next = newN;
                temp  = temp -> next;
            }
        }
        ListNode*newHead = ans -> next;
        delete ans;
        return newHead;
        
    }
};