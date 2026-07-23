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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        vector<int>v;

        ListNode* temp = list1;

        while( temp != NULL ){
            v.push_back(temp -> val);
            temp = temp -> next;
        }

        temp = list2;

        while( temp != NULL ){
            v.push_back(temp->val);
            temp  = temp -> next;
        }

        sort(v.begin(),v.end());

        ListNode*dummy = new ListNode(0);

        ListNode* curr = dummy;

        for( int x : v ){
            curr -> next = new ListNode(x);
            curr = curr -> next;
        }

        return dummy -> next;
        
    }
};