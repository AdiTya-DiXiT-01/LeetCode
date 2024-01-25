class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        if (head == NULL or head->next == NULL or head->next->next == NULL)
            return NULL;

        ListNode *fast = head, *slow = head;

        do {
            if (fast == NULL or fast->next == NULL)
                return NULL;

            fast = fast->next->next;
            slow = slow->next;
        } while (fast != slow);

        fast = head;

        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }

        return slow;
    }
};
