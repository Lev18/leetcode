class Solution {
public:
        ListNode* partition(ListNode* head, int x) {   
         ListNode* head_iter = new ListNode(101);
         head_iter->next = head;
         ListNode* iter_slow = head;
         ListNode* iter_fast = head;
         
         bool head_chgd = true;
         while (iter_fast != nullptr && iter_fast->val < x) {
             iter_slow = iter_slow->next;
             iter_fast = iter_fast->next;
             head_iter = head_iter->next;
             if (head_chgd) head_chgd = false;
         } 

         while (iter_fast != nullptr) {
             if (iter_fast->val < x) {
               iter_slow->next = iter_fast->next;
               iter_fast->next = head_iter->next;
               head_iter->next = iter_fast;
               iter_fast = iter_slow->next;
               head_iter = head_iter->next;
               if (head_chgd) {
                 head = head_iter;
                 head_chgd = false;
               }
             }
             else {
                 iter_slow = iter_fast;
                 iter_fast = iter_fast->next;
             }
         
         }
         return head;
    }
};
