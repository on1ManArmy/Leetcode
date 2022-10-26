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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL or head->next == NULL or k == 0){
            return head;
        }
        
        int cnt = 1;
        ListNode* temp = head;
        
        /// compute the length
        while(temp->next != NULL){
            cnt++;
            temp = temp->next;
        }
        
        temp->next = head;
        k = k % cnt;
        
        /// go till that node
        int rem = cnt - k;
        while(rem--){
            temp = temp->next;
        }
        
        /// break and connect the link
        head = temp->next;
        temp->next = NULL;
        
        return head;
    }
};