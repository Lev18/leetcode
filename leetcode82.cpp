#include <set>
#include <iostream>
 
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dumy = new ListNode();
        dumy->next = head;
        ListNode* slow = dumy;
        ListNode* fast = head;

        std::set<int> st;
        while (fast != nullptr) {
            if (fast->val == slow->val) { 
                st.insert(slow->val);
            } 
            slow = slow->next;
            fast = fast->next;
        }
        
        ListNode* slow_2 = dumy;
        ListNode* mid = head;
        ListNode* fast_2 = head;

        while (fast_2 != nullptr && mid != nullptr) {
            if (st.find(mid->val) != st.end()) {
                mid = mid->next;
                continue;
            }
            else if (st.find(fast_2->val)  != st.end()){
                slow_2->next = fast_2->next;
                fast_2 = fast_2->next;
            }
            else {
                slow_2 = slow_2->next;
                fast_2 = fast_2->next;     
            }   
        }
        return head;
    }
};

void push(ListNode** stack, int value) {
  
  if (stack == NULL) {
    *stack = new ListNode{value};
  }
  else {
    ListNode* tmp = new ListNode{value};
    tmp->next = *stack;
    *stack = tmp;
  }
}

int main() {
  ListNode* lst = new ListNode(4);
  push(&lst,3);
  push(&lst,2);
  push(&lst,2);
  push(&lst,1);
  push(&lst,0);
  
  Solution s;
  ListNode* n = s.deleteDuplicates(lst);
  return 0;
}
