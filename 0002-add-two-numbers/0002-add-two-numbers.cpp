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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        ListNode* ans = new ListNode(0);
        ListNode* t = ans;

        int carry = 0;

        while (temp1 != nullptr || temp2 != nullptr || carry != 0) {
            int sum = carry;

            if (temp1 != nullptr) {
                sum += temp1->val;
                temp1 = temp1->next;
            }

            if (temp2 != nullptr) {
                sum += temp2->val;
                temp2 = temp2->next;
            }

            carry = sum / 10;
            t->next = new ListNode(sum % 10);
            t = t->next;
        }

        return ans->next;
    }
};