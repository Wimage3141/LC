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
        ListNode* temp = new ListNode();
        ListNode* curr = temp;
        int carry = 0;
        while(l1 || l2) {
            if(l1 && l2) {
                int sum = l1->val + l2->val + carry;
                carry = 0;
                if(sum > 9) {
                    carry = sum / 10;
                    sum %= 10;
                }
                ListNode* newNode = new ListNode(sum);
                curr->next = newNode;
                l1 = l1->next;
                l2 = l2->next;
            }
            else if(l1) {
                int sum = l1->val + carry;
                carry = 0;
                if(sum > 9) {
                    carry = sum / 10;
                    sum %= 10;
                }
                ListNode* newNode = new ListNode(sum);
                curr->next = newNode;
                l1 = l1->next;
            }
            else {
                int sum = l2->val + carry;
                carry = 0;
                if(sum > 9) {
                    carry = sum / 10;
                    sum %= 10;
                }
                ListNode* newNode = new ListNode(sum);
                curr->next = newNode;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        if(carry > 0) {
            ListNode* carryNode = new ListNode(carry);
            curr->next = carryNode;
        }
        ListNode* newHead = temp->next;
        delete temp;
        return newHead;
    }
};