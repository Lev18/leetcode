#include <iostream>

struct ListNode {
    int val;
    ListNode* next;

    ListNode () {}
    ListNode (int x) : val(x), next(nullptr) {}
    ListNode (int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode* sumOfNumber(ListNode* l1, ListNode* l2) {
            ListNode* ans = new ListNode();
            ListNode* tmp = ans;

            int carry {0};

            while(l1 || l2 || carry) {
                int sum = carry;
                if(l1) {
                    sum += l1 -> val;
                    l1 = l1 -> next;
                }

                if(l2) {
                    sum += l2 -> val;
                    l2 = l2 -> next;
                }
                carry = sum / 10;
                tmp -> next = new ListNode(sum % 10);
                tmp = tmp -> next;
            }
            return ans -> next;
        }
};

int main() {
    ListNode* l1 = new ListNode(2);
    l1 -> next = new ListNode(4);
    l1 -> next -> next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2 -> next = new ListNode(6);
    l2 -> next -> next = new ListNode(4);

    Solution sol;

    ListNode* ans = sol.sumOfNumber(l1, l2);

    while(ans) {
            std::cout << ans -> val ;
            ans = ans -> next;
        if(ans) {
            std::cout << "->";
        }
    }
    std::cout << std::endl;

    while(l1) {
        ListNode* tmp = l1;
        l1 = l1 -> next;
        delete tmp;
    }

    while(l2) {
        ListNode* tmp = l2;
        l2 = l2 -> next;
        delete tmp;
    }
    return 0;
}
