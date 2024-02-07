#include <iostream>

struct ListNode {
  int val;
  ListNode* next;
  ListNode(): val(0), next(nullptr) {}
  ListNode(int x): val(x), next(nullptr) {}
  ListNode(int x, ListNode* list): val(x), next(list) {} 
};

ListNode* deleteDup(ListNode* head) {
  ListNode* tmp = head ; 
  if(head -> next == nullptr){
    return 0;}  
  if(head-> val == head ->next ->val){
    head  = tmp -> next;
    delete tmp;
    return deleteDup(head);   
    }
    head -> next = deleteDup(head -> next);
  return head;
  
}

int main() {
  ListNode* head = new ListNode(7,nullptr);
   ListNode* node1= new ListNode(6,head);
   ListNode* node5= new ListNode(6,node1);
    ListNode* node2 = new ListNode(4,node5);
     ListNode* node3 = new ListNode(4,node2);
     ListNode* node4 = deleteDup(node3);
  return 0;
}
