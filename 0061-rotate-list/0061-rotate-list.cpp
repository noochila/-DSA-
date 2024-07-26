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

        ListNode* curr = head;

        if (head == nullptr || head->next == nullptr)
            return head;

        int n = 1;

        while (curr->next != nullptr) {
            curr = curr->next;
            n++;
        }

        int r = k % n;

        if (r == 0)
        return head;

        curr->next = head;

        curr = head;
        int req = n - r;
        ListNode* prev = nullptr;
        ListNode* start = head;

     
        while (curr->next) {
            if (req == 1) {
                prev = curr->next;
                curr->next = nullptr;
                curr = prev;
                head = prev;
                break;

            } else {
                req--;
                curr = curr->next;
            }
        }

        return head;
    }
};