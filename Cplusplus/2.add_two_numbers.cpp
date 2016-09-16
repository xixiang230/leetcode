#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
    public: 
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode* cursor = new ListNode(0);
            ListNode* head = cursor;
            int carry = 0 ;
            int res = 0;
            while(l1 != NULL || l2 != NULL) {
                if (l1 == NULL && l2 != NULL) {
                    res = l2->val + carry;
                    l2 = l2->next;
                } else if (l2 == NULL && l1 != NULL) {
                    res = l1->val + carry;
                    l1 = l1->next;
                } else {
                    res = l1->val + l2->val + carry;
                    l1 = l1->next;
                    l2 = l2->next;
                }
                carry = res / 10;
                cursor->next = new ListNode(res % 10);
                cursor = cursor->next;
            }
            if (carry != 0) {
                cursor->next = new ListNode(1);
            }
            return head->next;
        }
};
int main(void) {
    int in_value = 0;
    ListNode* l1 = new ListNode(5);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    Solution st;
    ListNode* res = st.addTwoNumbers(l1, l2);
    while (res != NULL) {
        std::cout << res->val << std::endl;
        res = res->next;
    }
}
