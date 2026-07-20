class Solution {
public:
    void reorderList(ListNode* hed) {
        if (!hed || !hed->next) return;

        ListNode *slw = hed, *fst = hed;

        while (fst->next && fst->next->next) {
            slw = slw->next;
            fst = fst->next->next;
        }

        ListNode *cur = slw->next;
        slw->next = nullptr;

        ListNode *prv = nullptr;

        while (cur) {
            ListNode *nxt = cur->next;
            cur->next = prv;
            prv = cur;
            cur = nxt;
        }

        ListNode *one = hed;
        ListNode *two = prv;

        while (two) {
            ListNode *tmp = one->next;
            one->next = two;
            one = tmp;

            tmp = two->next;
            two->next = one;
            two = tmp;
        }
    }
};